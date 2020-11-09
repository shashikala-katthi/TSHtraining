#include <gst/gst.h>
#include<stdio.h>

int
main (int argc, char *argv[])
{
  GstElement *pipeline, *bin, *equalizer, *convert, *sink;
  GstPad *pad, *ghost_pad;
  GstBus *bus;
  GstMessage *msg;

  /* Initialize GStreamer */
printf("shashi:main:gst_init\n");
  gst_init (&argc, &argv);

  /* Build the pipeline */
printf("shashi:main:gst_parse_launch\n");
  pipeline =
      gst_parse_launch
      ("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",
      NULL);

  /* Create the elements inside the sink bin */
printf("shashi:main:gst_element_factory_make\n");
  equalizer = gst_element_factory_make ("equalizer-3bands", "equalizer");
printf("shashi:main:gst_init\n");
  convert = gst_element_factory_make ("audioconvert", "convert");
  sink = gst_element_factory_make ("autoaudiosink", "audio_sink");
  if (!equalizer || !convert || !sink) {
    g_printerr ("Not all elements could be created.\n");
    return -1;
  }

  /* Create the sink bin, add the elements and link them */
printf("shashi:main:gst_bin_new\n");
  bin = gst_bin_new ("audio_sink_bin");
printf("shashi:main:gst_bin_add_many\n");
  gst_bin_add_many (GST_BIN (bin), equalizer, convert, sink, NULL);
printf("shashi:main:gst_element_link_many \n");
  gst_element_link_many (equalizer, convert, sink, NULL);
printf("shashi:main:gst_element_get_static_pad \n");
  pad = gst_element_get_static_pad (equalizer, "sink");
printf("shashi:main:gst_ghost_pad_new \n");
  ghost_pad = gst_ghost_pad_new ("sink", pad);
printf("shashi:main:gst_pad_set_active\n");
  gst_pad_set_active (ghost_pad, TRUE);
printf("shashi:main:gst_element_add_pad\n");
  gst_element_add_pad (bin, ghost_pad);
printf("shashi:main:gst_object_unref \n");
  gst_object_unref (pad);

  /* Configure the equalizer */
printf("shashi:main:g_object_set:band1\n");
  g_object_set (G_OBJECT (equalizer), "band1", (gdouble) - 24.0, NULL);
printf("shashi:main:g_object_set:band2 \n");
  g_object_set (G_OBJECT (equalizer), "band2", (gdouble) - 24.0, NULL);

  /* Set playbin2's audio sink to be our sink bin */
printf("shashi:main:g_object_set:audio sink\n");
  g_object_set (GST_OBJECT (pipeline), "audio-sink", bin, NULL);

  /* Start playing */
printf("shashi:main: gst_element_set_state:as playing\n");
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Wait until error or EOS */
printf("shashi:main:gst_element_get_bus \n");
  bus = gst_element_get_bus (pipeline);
  msg =
      gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
      GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Free resources */
  if (msg != NULL){
printf("shashi:main:gst_message_unref:to unref msg\n");
    gst_message_unref (msg);
}
printf("shashi:main:gst_object_unref:for unref bus \n");
  gst_object_unref (bus);
printf("shashi:main:gst_element_set_state:set as null\n");
  gst_element_set_state (pipeline, GST_STATE_NULL);
printf("shashi:main:gst_object_unref:to unref pipeline\n");
  gst_object_unref (pipeline);
  return 0;
}
