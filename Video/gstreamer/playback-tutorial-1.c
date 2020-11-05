#include <stdio.h>
#include <gst/gst.h>

/* Structure to contain all our information, so we can pass it around */
typedef struct _CustomData
{
  GstElement *playbin;          /* Our one and only element */

  gint n_video;                 /* Number of embedded video streams */
  gint n_audio;                 /* Number of embedded audio streams */
  gint n_text;                  /* Number of embedded subtitle streams */

  gint current_video;           /* Currently playing video stream */
  gint current_audio;           /* Currently playing audio stream */
  gint current_text;            /* Currently playing subtitle stream */

  GMainLoop *main_loop;         /* GLib's Main Loop */
} CustomData;

/* playbin flags */
typedef enum
{
  GST_PLAY_FLAG_VIDEO = (1 << 0),       /* We want video output */
  GST_PLAY_FLAG_AUDIO = (1 << 1),       /* We want audio output */
  GST_PLAY_FLAG_TEXT = (1 << 2) /* We want subtitle output */
} GstPlayFlags;

/* Forward definition for the message and keyboard processing functions */
static gboolean handle_message (GstBus * bus, GstMessage * msg,
    CustomData * data);
static gboolean handle_keyboard (GIOChannel * source, GIOCondition cond,
    CustomData * data);

int
main (int argc, char *argv[])
{
  CustomData data;
  GstBus *bus;
  GstStateChangeReturn ret;
  gint flags;
  GIOChannel *io_stdin;

printf("shashi:main :gst_init\n");
  /* Initialize GStreamer */
  gst_init (&argc, &argv);

printf("shashi:main :gst_element_factory_make\n");
  /* Create the elements */
  data.playbin = gst_element_factory_make ("playbin", "playbin");

printf("shashi:main :g_printerr\n");
  if (!data.playbin) {
    g_printerr ("Not all elements could be created.\n");
    return -1;
  }

printf("shashi:main :g_object_set:playbin\n");
  /* Set the URI to play */
  g_object_set (data.playbin, "uri",
      "https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_cropped_multilingual.webm",
      NULL);

printf("shashi:main :g_object_get:audio and video\n");
  /* Set flags to show Audio and Video but ignore Subtitles */
  g_object_get (data.playbin, "flags", &flags, NULL);
  flags |= GST_PLAY_FLAG_VIDEO | GST_PLAY_FLAG_AUDIO | GST_PLAY_FLAG_TEXT;

printf("shashi:main :g_object_set:audio and video\n");
  g_object_set (data.playbin, "flags", flags, NULL);

printf("shashi:main :g_object_set:playbin inernal decisions\n");
  /* Set connection speed. This will affect some internal decisions of playbin */
  g_object_set (data.playbin, "connection-speed", 56, NULL);

printf("shashi:main :gst_object_get_bus\n");
  /* Add a bus watch, so we get notified when a message arrives */
  bus = gst_element_get_bus (data.playbin);

printf("shashi:main :gst_bus_add_watch:message notifications\n");
  gst_bus_add_watch (bus, (GstBusFunc) handle_message, &data);

  /* Add a keyboard watch so we get notified of keystrokes */
#ifdef G_OS_WIN32
  io_stdin = g_io_channel_win32_new_fd (fileno (stdin));
#else
  io_stdin = g_io_channel_unix_new (fileno (stdin));
#endif
printf("shashi:main :g_io_add_watch:keyboard notifications\n");
  g_io_add_watch (io_stdin, G_IO_IN, (GIOFunc) handle_keyboard, &data);


  /* Start playing */
printf("shashi:main :gst_element_set_state:to set state as playing\n");
  ret = gst_element_set_state (data.playbin, GST_STATE_PLAYING);
  if (ret == GST_STATE_CHANGE_FAILURE) {
printf("shashi:main :g_printerr:if pipeline not able to as playing state\n");
    g_printerr ("Unable to set the pipeline to the playing state.\n");

printf("shashi:main :gst_object_unref:to unref the playbin element\n");
    gst_object_unref (data.playbin);
    return -1;
  }

  /* Create a GLib Main Loop and set it to run */
printf("shashi:main :g_main_loop_new\n");
  data.main_loop = g_main_loop_new (NULL, FALSE);

printf("shashi:main :g_main_loop_run\n");
  g_main_loop_run (data.main_loop);

  /* Free resources */
printf("shashi:main :g_main_loop_run:to unref the main_loop\n");
  g_main_loop_unref (data.main_loop);
printf("shashi:main :g_io_channel_unref:to inref the io_channel\n");
  g_io_channel_unref (io_stdin);
printf("shashi:main :gst_object_unref:to unref the bus\n");
  gst_object_unref (bus);
printf("shashi:main :gst_element_set_state:as null\n");
  gst_element_set_state (data.playbin, GST_STATE_NULL);
printf("shashi:main :gst_object_unref:to unref playbin\n");
  gst_object_unref (data.playbin);

  return 0;
}

/* Extract some metadata from the streams and print it on the screen */
static void
analyze_streams (CustomData * data)
{
printf("shashi:analyze_streams::open\n");
  gint i;
  GstTagList *tags;
  gchar *str;
  guint rate;
  guint framerate;
  /* Read some properties */
printf("shashi:analyze_streams::g_object_get:for video\n");
  g_object_get (data->playbin, "n-video", &data->n_video, NULL);

printf("shashi:analyze_streams::g_object_get:for audio\n");
  g_object_get (data->playbin, "n-audio", &data->n_audio, NULL);

printf("shashi:analyze_streams::g_object_get:for text\n");
  g_object_get (data->playbin, "n-text", &data->n_text, NULL);

  g_print ("%d video stream(s), %d audio stream(s), %d text stream(s)\n",
      data->n_video, data->n_audio, data->n_text);

  g_print ("\n");
  for (i = 0; i < data->n_video; i++) {
    tags = NULL;
    /* Retrieve the stream's video tags */
printf("shashi:analyze_streams::g_signal_emit_by_name:for video tags\n");
    g_signal_emit_by_name (data->playbin, "get-video-tags", i, &tags);
    if (tags) {
      g_print ("video stream %d:\n", i);
printf("shashi:analyze_streams::gst_tag_list_get_string:for video stream\n");
      gst_tag_list_get_string (tags, GST_TAG_VIDEO_CODEC, &str);
      g_print ("  codec: %s\n", str ? str : "unknown");
      g_free (str);
printf("shashi:analyze_streams::gst_tag_list_unref:to unref video tags\n");
      gst_tag_list_unref (tags);
    }
  }

  g_print ("\n");
  for (i = 0; i < data->n_audio; i++) {
    tags = NULL;
    /* Retrieve the stream's audio tags */
printf("shashi:analyze_streams::g_signal_emit_by_name:for audio tags\n");
    g_signal_emit_by_name (data->playbin, "get-audio-tags", i, &tags);
    if (tags) {
      g_print ("audio stream %d:\n", i);
printf("shashi:analyze_streams::gst_tag_list_get_string:for audio stream\n");
      if (gst_tag_list_get_string (tags, GST_TAG_AUDIO_CODEC, &str)) {
        g_print ("  codec: %s\n", str);
        g_free (str);
      }
printf("shashi:analyze_streams::gst_tag_list_get_string:for audio stream language\n");
      if (gst_tag_list_get_string (tags, GST_TAG_LANGUAGE_CODE, &str)) {
        g_print ("  language: %s\n", str);
        g_free (str);
      }
printf("shashi:analyze_streams::gst_tag_list_get_uint:for audio stream bitrate\n");
      if (gst_tag_list_get_uint (tags, GST_TAG_BITRATE, &rate)) {
        g_print ("  bitrate: %d\n", rate);
      }
printf("shashi:analyze_streams::gst_tag_list_unref:to unref audio tags\n");
      gst_tag_list_unref (tags);
    }
  }

  g_print ("\n");
  for (i = 0; i < data->n_text; i++) {
    tags = NULL;
    /* Retrieve the stream's subtitle tags */
printf("shashi:analyze_streams::g_signal_emit_by_name:for text tags\n");
    g_signal_emit_by_name (data->playbin, "get-text-tags", i, &tags);
    if (tags) {
      g_print ("subtitle stream %d:\n", i);
printf("shashi:analyze_streams::gst_tag_list_get_string:for subtitle stream\n");
      if (gst_tag_list_get_string (tags, GST_TAG_LANGUAGE_CODE, &str)) {
        g_print ("  language: %s\n", str);
        g_free (str);
      }
printf("shashi:analyze_streams::gst_tag_list_unref:to unref subtitle tags\n");
      gst_tag_list_unref (tags);
    }
  }
printf("shashi:analyze_streams::g_object_get:for current video stream\n");
  g_object_get (data->playbin, "current-video", &data->current_video, NULL);

printf("shashi:analyze_streams::g_object_get:for current audio stream\n");
  g_object_get (data->playbin, "current-audio", &data->current_audio, NULL);

printf("shashi:analyze_streams::g_object_get:for current text stream\n");
  g_object_get (data->playbin, "current-text", &data->current_text, NULL);

  g_print ("\n");
  g_print
      ("Currently playing video stream %d, audio stream %d and text stream %d\n",
      data->current_video, data->current_audio, data->current_text);
  g_print
      ("Type any number and hit ENTER to select a different audio stream\n");

printf("shashi:analyze_streams::close");
}

/* Process messages from GStreamer */
static gboolean
handle_message (GstBus * bus, GstMessage * msg, CustomData * data)
{
printf("shashi:handle_message::open\n");
  GError *err;
  gchar *debug_info;

  switch (GST_MESSAGE_TYPE (msg)) {
    case GST_MESSAGE_ERROR:
printf("shashi:handle_message:gst_message_parse_error\n");
      gst_message_parse_error (msg, &err, &debug_info);
      g_printerr ("Error received from element %s: %s\n",
          GST_OBJECT_NAME (msg->src), err->message);
      g_printerr ("Debugging information: %s\n",
          debug_info ? debug_info : "none");
      g_clear_error (&err);
      g_free (debug_info);
printf("shashi:handle_message:g_main_loop_quit\n");
      g_main_loop_quit (data->main_loop);
printf("shashi:handle_message:switch:case 1:close\n");
      break;
    case GST_MESSAGE_EOS:
      g_print ("End-Of-Stream reached.\n");
printf("shashi:handle_message:g_main_loop_quit\n");
      g_main_loop_quit (data->main_loop);
printf("shashi:handle_message:switch:close 2:close\n");
      break;
    case GST_MESSAGE_STATE_CHANGED:{
      GstState old_state, new_state, pending_state;
printf("shashi:handle_message:gst_message_parse_state_changed\n");
      gst_message_parse_state_changed (msg, &old_state, &new_state,
          &pending_state);
      if (GST_MESSAGE_SRC (msg) == GST_OBJECT (data->playbin)) {
        if (new_state == GST_STATE_PLAYING) {
          /* Once we are in the playing state, analyze the streams */
printf("shashi:handle_message::analyze_streams\n");
          analyze_streams (data);
        }
      }
    }
printf("shashi:handle_message:switch:case 3:close\n");
      break;
    default:
//printf("shashi:handle_message::switch:default:close\n");
      break;
  }
printf("shashi:handle_message::close\n");
  /* We want to keep receiving messages */
  return TRUE;
}

/* Process keyboard input */
static gboolean
handle_keyboard (GIOChannel * source, GIOCondition cond, CustomData * data)
{
printf("shashi:handle_keyboard::open\n");
  gchar *str = NULL;
printf("shashi:handle_keyboard::g_io_channel_read_line\n");
  if (g_io_channel_read_line (source, &str, NULL, NULL,
          NULL) == G_IO_STATUS_NORMAL) {
    int index = g_ascii_strtoull (str, NULL, 0);
    if (index < 0 || index >= data->n_audio) {
      g_printerr ("Index out of bounds\n");
    } else {
      /* If the input was a valid audio stream index, set the current audio stream */
      g_print ("Setting current audio stream to %d\n", index);
printf("shashi:handle_keyboard::g_object_set:to change audio stream\n");
      g_object_set (data->playbin, "current-audio", index, NULL);
    }
  }
  g_free (str);
printf("shashi:handle_keyboard::close\n");
  return TRUE;
}
