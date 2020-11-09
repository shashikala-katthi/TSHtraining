#include <gst/gst.h>
#include <gst/audio/audio.h>
#include <string.h>
#include<stdio.h>

#define CHUNK_SIZE 1024         /* Amount of bytes we are sending in each buffer */
#define SAMPLE_RATE 44100       /* Samples per second we are sending */

/* Structure to contain all our information, so we can pass it to callbacks */
typedef struct _CustomData
{
  GstElement *pipeline;
  GstElement *app_source;

  guint64 num_samples;          /* Number of samples generated so far (for timestamp generation) */
  gfloat a, b, c, d;            /* For waveform generation */

  guint sourceid;               /* To control the GSource */

  GMainLoop *main_loop;         /* GLib's Main Loop */
} CustomData;

/* This method is called by the idle GSource in the mainloop, to feed CHUNK_SIZE bytes into appsrc.
 * The ide handler is added to the mainloop when appsrc requests us to start sending data (need-data signal)
 * and is removed when appsrc has enough data (enough-data signal).
 */
static gboolean
push_data (CustomData * data)
{
printf("shashi:push_data:open\n");
  GstBuffer *buffer;
  GstFlowReturn ret;
  int i;
  GstMapInfo map;
  gint16 *raw;
  gint num_samples = CHUNK_SIZE / 2;    /* Because each sample is 16 bits */
  gfloat freq;

  /* Create a new empty buffer */
printf("shashi:push_data:gst_buffer_new_and_alloc\n");
  buffer = gst_buffer_new_and_alloc (CHUNK_SIZE);

  /* Set its timestamp and duration */
printf("shashi:push_data:gst_util_uint64_scale:for timestamp \n");
  GST_BUFFER_TIMESTAMP (buffer) =
      gst_util_uint64_scale (data->num_samples, GST_SECOND, SAMPLE_RATE);
printf("shashi:push_data:gst_util_uint64_scale:for duration \n");
  GST_BUFFER_DURATION (buffer) =
      gst_util_uint64_scale (num_samples, GST_SECOND, SAMPLE_RATE);

  /* Generate some psychodelic waveforms */
printf("shashi:push_data: gst_buffer_map:for write mode \n");
  gst_buffer_map (buffer, &map, GST_MAP_WRITE);
  raw = (gint16 *) map.data;
  data->c += data->d;
  data->d -= data->c / 1000;
  freq = 1100 + 1000 * data->d;
  for (i = 0; i < num_samples; i++) {
    data->a += data->b;
    data->b -= data->a / freq;
    raw[i] = (gint16) (500 * data->a);
  }
printf("shashi:push_data:gst_buffer_unmap \n");
  gst_buffer_unmap (buffer, &map);
  data->num_samples += num_samples;

  /* Push the buffer into the appsrc */
printf("shashi:push_data:  g_signal_emit_by_name:for push-buffer\n");
  g_signal_emit_by_name (data->app_source, "push-buffer", buffer, &ret);

  /* Free the buffer now that we are done with it */
printf("shashi:push_data: gst_buffer_unref \n");
  gst_buffer_unref (buffer);

  if (ret != GST_FLOW_OK) {
printf("shashi:push_data:error occured\n");
    /* We got some error, stop sending data */
    return FALSE;
  }
printf("shashi:push_data: close \n");
  return TRUE;
}

/* This signal callback triggers when appsrc needs data. Here, we add an idle handler
 * to the mainloop to start pushing data into the appsrc */
static void
start_feed (GstElement * source, guint size, CustomData * data)
{
printf("shashi:start_feed:open\n");
  if (data->sourceid == 0) {
    g_print ("Start feeding\n");
printf("shashi:start_feed:g_idle_add:for push_data callback\n");
    data->sourceid = g_idle_add ((GSourceFunc) push_data, data);
  }
printf("shashi:start_feed:close\n");
}

/* This callback triggers when appsrc has enough data and we can stop sending.
 * We remove the idle handler from the mainloop */
static void
stop_feed (GstElement * source, CustomData * data)
{
printf("shashi:stop_feed:open\n");
  if (data->sourceid != 0) {
    g_print ("Stop feeding\n");
printf("shashi:stop_feed:g_source_remove\n");
    g_source_remove (data->sourceid);
    data->sourceid = 0;
  }
printf("shashi:stop_feed:close\n");
}

/* This function is called when an error message is posted on the bus */
static void
error_cb (GstBus * bus, GstMessage * msg, CustomData * data)
{
printf("shashi:error_cb:open\n");
  GError *err;
  gchar *debug_info;

  /* Print error details on the screen */
printf("shashi:error_cb:gst_message_parse_error\n");
  gst_message_parse_error (msg, &err, &debug_info);
  g_printerr ("Error received from element %s: %s\n",
      GST_OBJECT_NAME (msg->src), err->message);
  g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
  g_clear_error (&err);
  g_free (debug_info);
printf("shashi:error_cb:g_main_loop_quit\n");
  g_main_loop_quit (data->main_loop);
printf("shashi:error_cb:close\n");
}

/* This function is called when playbin has created the appsrc element, so we have
 * a chance to configure it. */
static void
source_setup (GstElement * pipeline, GstElement * source, CustomData * data)
{
printf("shashi:source_setup:open\n");
  GstAudioInfo info;
  GstCaps *audio_caps;

  g_print ("Source has been created. Configuring.\n");
  data->app_source = source;

  /* Configure appsrc */
printf("shashi:source_setup: gst_audio_info_set_format\n");
  gst_audio_info_set_format (&info, GST_AUDIO_FORMAT_S16, SAMPLE_RATE, 1, NULL);
printf("shashi:source_setup:gst_audio_info_to_caps\n");
  audio_caps = gst_audio_info_to_caps (&info);
printf("shashi:source_setup: g_object_set\n");
  g_object_set (source, "caps", audio_caps, "format", GST_FORMAT_TIME, NULL);
printf("shashi:source_setup:g_signal_connect:for start_feed callback\n");
  g_signal_connect (source, "need-data", G_CALLBACK (start_feed), data);
printf("shashi:source_setup:g_signal_connect:for stop_feed callback\n");
  g_signal_connect (source, "enough-data", G_CALLBACK (stop_feed), data);
printf("shashi:source_setup:open\n");
  gst_caps_unref (audio_caps);
printf("shashi:source_setup:close\n");
}

int
main (int argc, char *argv[])
{
  CustomData data;
  GstBus *bus;

  /* Initialize cumstom data structure */
  memset (&data, 0, sizeof (data));
  data.b = 1;                   /* For waveform generation */
  data.d = 1;

  /* Initialize GStreamer */
printf("shashi:main:gst_init\n");
  gst_init (&argc, &argv);

  /* Create the playbin element */
printf("shashi:main:gst_parse_launch:for playbin\n");
  data.pipeline = gst_parse_launch ("playbin uri=appsrc://", NULL);
printf("shashi:main:g_signal_connect:source_setup callback\n");
  g_signal_connect (data.pipeline, "source-setup", G_CALLBACK (source_setup),
      &data);

  /* Instruct the bus to emit signals for each received message, and connect to the interesting signals */
printf("shashi:main:gst_element_get_bus \n");
  bus = gst_element_get_bus (data.pipeline);
printf("shashi:main:gst_bus_add_signal_watch \n");
  gst_bus_add_signal_watch (bus);
printf("shashi:main:g_signal_connect:to error_cb callback\n");
  g_signal_connect (G_OBJECT (bus), "message::error", (GCallback) error_cb,
      &data);
printf("shashi:main:gst_object_unref:to unref the bus\n");
  gst_object_unref (bus);

  /* Start playing the pipeline */
printf("shashi:main:gst_element_set_state :to set pipeline state as playing\n");
  gst_element_set_state (data.pipeline, GST_STATE_PLAYING);

  /* Create a GLib Main Loop and set it to run */
printf("shashi:main:g_main_loop_new \n");
  data.main_loop = g_main_loop_new (NULL, FALSE);
printf("shashi:main:g_main_loop_run\n");
  g_main_loop_run (data.main_loop);

  /* Free resources */
printf("shashi:main:gst_element_set_state :to set pipeline state as null\n");
  gst_element_set_state (data.pipeline, GST_STATE_NULL);
printf("shashi:main:gst_object_unref:to unref the pipeline\n");
  gst_object_unref (data.pipeline);
  return 0;
}
