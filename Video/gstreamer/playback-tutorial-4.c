#include <gst/gst.h>
#include <string.h>
#include<stdio.h>

#define GRAPH_LENGTH 78

/* playbin flags */
typedef enum
{
  GST_PLAY_FLAG_DOWNLOAD = (1 << 7)     /* Enable progressive download (on selected formats) */
} GstPlayFlags;

typedef struct _CustomData
{
  gboolean is_live;
  GstElement *pipeline;
  GMainLoop *loop;
  gint buffering_level;
} CustomData;

static void
got_location (GstObject * gstobject, GstObject * prop_object, GParamSpec * prop,
    gpointer data)
{
printf("shashi:got_location:open\n");
  gchar *location;

printf("shashi:got_location:g_object_get\n");
  g_object_get (G_OBJECT (prop_object), "temp-location", &location, NULL);
  g_print ("Temporary file: %s\n", location);
  g_free (location);
  /* Uncomment this line to keep the temporary file after the program exits */
  /* g_object_set (G_OBJECT (prop_object), "temp-remove", FALSE, NULL); */
printf("shashi:got_location:close\n");
}

static void
cb_message (GstBus * bus, GstMessage * msg, CustomData * data)
{
printf("shashi:cb_message:open\n");
  switch (GST_MESSAGE_TYPE (msg)) {
    case GST_MESSAGE_ERROR:{
      GError *err;
      gchar *debug;
printf("shashi:cb_message:gst_message_parse_error\n");
      gst_message_parse_error (msg, &err, &debug);
      g_print ("Error: %s\n", err->message);
      g_error_free (err);
      g_free (debug);
printf("shashi:cb_message:gst_element_set_state:to set as ready\n");
      gst_element_set_state (data->pipeline, GST_STATE_READY);
printf("shashi:cb_message:g_main_loop_quit\n");
      g_main_loop_quit (data->loop);
printf("shashi:cb_message:case 1 close\n");
      break;
    }
    case GST_MESSAGE_EOS:
      /* end-of-stream */
printf("shashi:cb_message:gst_element_set_state:to set as ready\n");
      gst_element_set_state (data->pipeline, GST_STATE_READY);
printf("shashi:cb_message:g_main_loop_quit\n");
      g_main_loop_quit (data->loop);
printf("shashi:cb_message:case 2 close\n");
      break;
    case GST_MESSAGE_BUFFERING:
      /* If the stream is live, we do not care about buffering. */
      if (data->is_live)
printf("shashi:cb_message:case 3: data is live :close\n");
        break;

      gst_message_parse_buffering (msg, &data->buffering_level);

      /* Wait until buffering is complete before start/resume playing */
      if (data->buffering_level < 100){
printf("shashi:cb_message:gst_element_set_state:to set as paused\n");
        gst_element_set_state (data->pipeline, GST_STATE_PAUSED);
}
      else{
printf("shashi:cb_message:gst_element_set_state:to set as playing\n");
        gst_element_set_state (data->pipeline, GST_STATE_PLAYING);
printf("shashi:cb_message:case 3: data is before start/resume:close\n");
}
      break;
    case GST_MESSAGE_CLOCK_LOST:
      /* Get a new clock */
printf("shashi:cb_message:gst_element_set_state:to set as paused\n");
      gst_element_set_state (data->pipeline, GST_STATE_PAUSED);
printf("shashi:cb_message:gst_element_set_state:to set as playing\n");
      gst_element_set_state (data->pipeline, GST_STATE_PLAYING);
printf("shashi:cb_message:case 4 close\n");
      break;
    default:
      /* Unhandled message */
      break;
  }
printf("shashi:cb_message:close\n");
}

static gboolean
refresh_ui (CustomData * data)
{
printf("shashi:refresh_ui:open\n");
  GstQuery *query;
  gboolean result;

printf("shashi:refresh_ui:gst_new_buffering\n");
  query = gst_query_new_buffering (GST_FORMAT_PERCENT);

printf("shashi:refresh_ui:gst_element_query\n");
  result = gst_element_query (data->pipeline, query);
  if (result) {
    gint n_ranges, range, i;
    gchar graph[GRAPH_LENGTH + 1];
    gint64 position = 0, duration = 0;

    memset (graph, ' ', GRAPH_LENGTH);
    graph[GRAPH_LENGTH] = '\0';

printf("shashi:refresh_ui:gst_query_get_n_buffering_ranges\n");
    n_ranges = gst_query_get_n_buffering_ranges (query);
    for (range = 0; range < n_ranges; range++) {
      gint64 start, stop;
printf("shashi:refresh_ui:gst_query_nth_buffering_range\n");
      gst_query_parse_nth_buffering_range (query, range, &start, &stop);
      start = start * GRAPH_LENGTH / (stop - start);
      stop = stop * GRAPH_LENGTH / (stop - start);
      for (i = (gint) start; i < stop; i++)
        graph[i] = '-';
    }
printf("shashi:refresh_ui:gst_element_query_position\n");
    if (gst_element_query_position (data->pipeline, GST_FORMAT_TIME, &position)
        && GST_CLOCK_TIME_IS_VALID (position)
        && gst_element_query_duration (data->pipeline, GST_FORMAT_TIME,
            &duration) && GST_CLOCK_TIME_IS_VALID (duration)) {
      i = (gint) (GRAPH_LENGTH * (double) position / (double) (duration + 1));
      graph[i] = data->buffering_level < 100 ? 'X' : '>';
    }
    g_print ("[%s]", graph);
    if (data->buffering_level < 100) {
      g_print (" Buffering: %3d%%", data->buffering_level);
    } else {
      g_print ("                ");
    }
    g_print ("\r");
  }
printf("shashi:refresh_ui:close\n");
  return TRUE;

}

int
main (int argc, char *argv[])
{
  GstElement *pipeline;
  GstBus *bus;
  GstStateChangeReturn ret;
  GMainLoop *main_loop;
  CustomData data;
  guint flags;

  /* Initialize GStreamer */
printf("shashi:main :gst_init\n");
  gst_init (&argc, &argv);

  /* Initialize our data structure */
  memset (&data, 0, sizeof (data));
  data.buffering_level = 100;

  /* Build the pipeline */
printf("shashi:main :gst_parse_launch:building the pipeline for playbin element\n");
  pipeline =
      gst_parse_launch
      ("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",
      NULL);
printf("shashi:main :gst_element_get_bus\n");
  bus = gst_element_get_bus (pipeline);

  /* Set the download flag */
printf("shashi:main :g_object_get\n");
  g_object_get (pipeline, "flags", &flags, NULL);
  flags |= GST_PLAY_FLAG_DOWNLOAD;
printf("shashi:main :g_object_set\n");
  g_object_set (pipeline, "flags", flags, NULL);

  /* Uncomment this line to limit the amount of downloaded data */
  /* g_object_set (pipeline, "ring-buffer-max-size", (guint64)4000000, NULL); */

  /* Start playing */
printf("shashi:main :gst_element_set_state:as playing\n");
  ret = gst_element_set_state (pipeline, GST_STATE_PLAYING);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    g_printerr ("Unable to set the pipeline to the playing state.\n");
printf("shashi:main :gst_object_unref:to unref the pipeline\n");
    gst_object_unref (pipeline);
    return -1;
  } else if (ret == GST_STATE_CHANGE_NO_PREROLL) {
    data.is_live = TRUE;
  }
printf("shashi:main :g_main_loop_new\n");
  main_loop = g_main_loop_new (NULL, FALSE);
  data.loop = main_loop;
  data.pipeline = pipeline;
printf("shashi:main :gst_bus_add_signal_watch:for bus to get messages\n");
  gst_bus_add_signal_watch (bus);

printf("shashi:main :g_signal_connect:for cb_message callback\n");
  g_signal_connect (bus, "message", G_CALLBACK (cb_message), &data);

printf("shashi:main :g_signal_connect:for got location callback\n");
  g_signal_connect (pipeline, "deep-notify::temp-location",
      G_CALLBACK (got_location), NULL);
printf("shashi:main :g_timeout_add_seconds:for refresh ui callback\n");
  /* Register a function that GLib will call every second */
  g_timeout_add_seconds (1, (GSourceFunc) refresh_ui, &data);

printf("shashi:main :g_main_loop_run\n");
  g_main_loop_run (main_loop);

  /* Free resources */
printf("shashi:main :g_main_loop_unref:to unref the main loop\n");
  g_main_loop_unref (main_loop);
printf("shashi:main :gst_object_unref:to unref the bus\n");
  gst_object_unref (bus);
printf("shashi:main :gst_element_set_state:as NULL\n");
  gst_element_set_state (pipeline, GST_STATE_NULL);
printf("shashi:main :gst_object_unref:to unref the pipeline\n");
  gst_object_unref (pipeline);

  g_print ("\n");
  return 0;
}
