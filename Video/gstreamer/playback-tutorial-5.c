#include <string.h>
#include <stdio.h>
#include <gst/gst.h>
#include <gst/video/colorbalance.h>

typedef struct _CustomData
{
  GstElement *pipeline;
  GMainLoop *loop;
} CustomData;

/* Process a color balance command */
static void
update_color_channel (const gchar * channel_name, gboolean increase,
    GstColorBalance * cb)
{
printf("shashi:update_color_channel:open\n");
  gdouble step;
  gint value;
  GstColorBalanceChannel *channel = NULL;
  const GList *channels, *l;

  /* Retrieve the list of channels and locate the requested one */
printf("shashi:update_color_channel:gst_color_balance_list_channels\n");
  channels = gst_color_balance_list_channels (cb);
  for (l = channels; l != NULL; l = l->next) {
    GstColorBalanceChannel *tmp = (GstColorBalanceChannel *) l->data;

    if (g_strrstr (tmp->label, channel_name)) {
      channel = tmp;
      break;
    }
  }
  if (!channel)
    return;

  /* Change the channel's value */
  step = 0.1 * (channel->max_value - channel->min_value);
printf("shashi:update_color_channel:gst_color_balance_get_value \n");
  value = gst_color_balance_get_value (cb, channel);
  if (increase) {
    value = (gint) (value + step);
    if (value > channel->max_value)
      value = channel->max_value;
  } else {
    value = (gint) (value - step);
    if (value < channel->min_value)
      value = channel->min_value;
  }
printf("shashi:update_color_channel:gst_color_balance_set_value\n");
  gst_color_balance_set_value (cb, channel, value);
printf("shashi:update_color_channel:close\n");
}

/* Output the current values of all Color Balance channels */
static void
print_current_values (GstElement * pipeline)
{
printf("shashi:print_current_values:open\n");
  const GList *channels, *l;

  /* Output Color Balance values */
printf("shashi:print_current_values:gst_color_balance_list_channels \n");
  channels = gst_color_balance_list_channels (GST_COLOR_BALANCE (pipeline));
  for (l = channels; l != NULL; l = l->next) {
    GstColorBalanceChannel *channel = (GstColorBalanceChannel *) l->data;
printf("shashi:print_current_values:gst_color_balance_get_value\n");
    gint value =
        gst_color_balance_get_value (GST_COLOR_BALANCE (pipeline), channel);
    g_print ("%s: %3d%% ", channel->label,
        100 * (value - channel->min_value) / (channel->max_value -
            channel->min_value));
  }
  g_print ("\n");
printf("shashi:print_current_values:close\n");
}

/* Process keyboard input */
static gboolean
handle_keyboard (GIOChannel * source, GIOCondition cond, CustomData * data)
{
printf("shashi:handle_keyboard:open\n");
  gchar *str = NULL;
printf("shashi:handle_keyboard:g_io_channel_read_line\n");
  if (g_io_channel_read_line (source, &str, NULL, NULL,
          NULL) != G_IO_STATUS_NORMAL) {
    return TRUE;
  }

  switch (g_ascii_tolower (str[0])) {
    case 'c':
      update_color_channel ("CONTRAST", g_ascii_isupper (str[0]),
          GST_COLOR_BALANCE (data->pipeline));
printf("shashi:handle_keyboard:case 'c':close\n");
      break;
    case 'b':
      update_color_channel ("BRIGHTNESS", g_ascii_isupper (str[0]),
          GST_COLOR_BALANCE (data->pipeline));
printf("shashi:handle_keyboard:case 'b':close\n");
      break;
    case 'h':
      update_color_channel ("HUE", g_ascii_isupper (str[0]),
          GST_COLOR_BALANCE (data->pipeline));
printf("shashi:handle_keyboard:case 'h':close\n");
      break;
    case 's':
      update_color_channel ("SATURATION", g_ascii_isupper (str[0]),
          GST_COLOR_BALANCE (data->pipeline));
printf("shashi:handle_keyboard:case 's':close\n");
      break;
    case 'q':
      g_main_loop_quit (data->loop);
printf("shashi:handle_keyboard:case 'q':close\n");
      break;printf("shashi:handle_keyboard:switch default:close\n");
    default:
      break;
  }

  g_free (str);
printf("shashi:handle_keyboard:print_current_values\n");
  print_current_values (data->pipeline);

  return TRUE;
printf("shashi:handle_keyboard:close\n");
}

int
main (int argc, char *argv[])
{
  CustomData data;
  GstStateChangeReturn ret;
  GIOChannel *io_stdin;

  /* Initialize GStreamer */
printf("shashi:main:gst_init\n");
  gst_init (&argc, &argv);

  /* Initialize our data structure */
  memset (&data, 0, sizeof (data));

  /* Print usage map */
  g_print ("USAGE: Choose one of the following options, then press enter:\n"
      " 'C' to increase contrast, 'c' to decrease contrast\n"
      " 'B' to increase brightness, 'b' to decrease brightness\n"
      " 'H' to increase hue, 'h' to decrease hue\n"
      " 'S' to increase saturation, 's' to decrease saturation\n"
      " 'Q' to quit\n");

  /* Build the pipeline */
printf("shashi:main: gst_parse_launch\n");
  data.pipeline =
      gst_parse_launch
      ("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",
      NULL);

  /* Add a keyboard watch so we get notified of keystrokes */
#ifdef G_OS_WIN32
  io_stdin = g_io_channel_win32_new_fd (fileno (stdin));
#else
  io_stdin = g_io_channel_unix_new (fileno (stdin));
#endif
printf("shashi:main: g_io_add_watch\n");
  g_io_add_watch (io_stdin, G_IO_IN, (GIOFunc) handle_keyboard, &data);

  /* Start playing */
printf("shashi:main:gst_element_set_state :set as playing\n");
  ret = gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    g_printerr ("Unable to set the pipeline to the playing state.\n");
printf("shashi:main:gst_object_unref\n");
    gst_object_unref (data.pipeline);
    return -1;
  }
printf("shashi:main:print_current_values\n");
  print_current_values (data.pipeline);

  /* Create a GLib Main Loop and set it to run */
printf("shashi:main: g_main_loop_new\n");
  data.loop = g_main_loop_new (NULL, FALSE);
printf("shashi:main:g_main_loop_run\n");
  g_main_loop_run (data.loop);

  /* Free resources */
printf("shashi:main:g_main_loop_unref:to unref the loop\n");
  g_main_loop_unref (data.loop);
printf("shashi:main: g_io_channel_unref:to unref io channel\n");
  g_io_channel_unref (io_stdin);
printf("shashi:main:gst_element_set_state:set as null\n");
  gst_element_set_state (data.pipeline, GST_STATE_NULL);
printf("shashi:main:gst_object_unref:to unref the pipeline\n");
  gst_object_unref (data.pipeline);
  return 0;
}
