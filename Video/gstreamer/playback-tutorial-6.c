#include <gst/gst.h>
#include<stdio.h>
/* playbin2 flags */
typedef enum
{
  GST_PLAY_FLAG_VIS = (1 << 3)  /* Enable rendering of visualizations when there is no video stream. */
} GstPlayFlags;

/* Return TRUE if this is a Visualization element */
static gboolean
filter_vis_features (GstPluginFeature * feature, gpointer data)
{
printf("shashi:filter_vis_features:open\n");
  GstElementFactory *factory;

  if (!GST_IS_ELEMENT_FACTORY (feature))
    return FALSE;
  factory = GST_ELEMENT_FACTORY (feature);
printf("shashi:filter_vis_features:gst_element_factory_get_klass \n");
  if (!g_strrstr (gst_element_factory_get_klass (factory), "Visualization"))
    return FALSE;

  return TRUE;
printf("shashi:filter_vis_features:close\n");
}

int
main (int argc, char *argv[])
{
  GstElement *pipeline, *vis_plugin;
  GstBus *bus;
  GstMessage *msg;
  GList *list, *walk;
  GstElementFactory *selected_factory = NULL;
  guint flags;

  /* Initialize GStreamer */
printf("shashi:main:gst_init\n");
  gst_init (&argc, &argv);

  /* Get a list of all visualization plugins */
printf("shashi:main: gst_registry_feature_filter\n");
  list =
      gst_registry_feature_filter (gst_registry_get (), filter_vis_features,
      FALSE, NULL);

  /* Print their names */
  g_print ("Available visualization plugins:\n");
  for (walk = list; walk != NULL; walk = g_list_next (walk)) {
    const gchar *name;
    GstElementFactory *factory;

    factory = GST_ELEMENT_FACTORY (walk->data);
printf("shashi:main:gst_element_factory_get_longname \n");
    name = gst_element_factory_get_longname (factory);
    g_print ("  %s\n", name);

    if (selected_factory == NULL || g_str_has_prefix (name, "Frequency spectrum scope")) {
      selected_factory = factory;
    }
  }

  /* Don't use the factory if it's still empty */
  /* e.g. no visualization plugins found */
  if (!selected_factory) {
    g_print ("No visualization plugins found!\n");
    return -1;
  }

  /* We have now selected a factory for the visualization element */
printf("shashi:main:gst_element_factory_get_longname\n");
  g_print ("Selected '%s'\n",
      gst_element_factory_get_longname (selected_factory));
printf("shashi:main:gst_element_factory_create \n");
  vis_plugin = gst_element_factory_create (selected_factory, NULL);
  if (!vis_plugin)
    return -1;

  /* Build the pipeline */
printf("shashi:main:gst_parse_launch\n");
  pipeline =
      gst_parse_launch ("playbin uri=http://radio.hbr1.com:19800/ambient.ogg",
      NULL);

  /* Set the visualization flag */
printf("shashi:main:g_object_get\n");
  g_object_get (pipeline, "flags", &flags, NULL);
  flags |= GST_PLAY_FLAG_VIS;
printf("shashi:main: g_object_set\n");
  g_object_set (pipeline, "flags", flags, NULL);

  /* set vis plugin for playbin2 */
printf("shashi:main: g_object_set:for playbin2\n");
  g_object_set (pipeline, "vis-plugin", vis_plugin, NULL);

  /* Start playing */
printf("shashi:main:gst_element_set_state:set as playing\n");
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Wait until error or EOS */
printf("shashi:main:gst_element_get_bus\n");
  bus = gst_element_get_bus (pipeline);
printf("shashi:main:gst_bus_timed_pop_filtered \n");
  msg =
      gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
      GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Free resources */
  if (msg != NULL){
printf("shashi:main: gst_message_unref:to unref the msg\n");
    gst_message_unref (msg);
}
printf("shashi:main: gst_plugin_feature_list_free:to free the list\n");
  gst_plugin_feature_list_free (list);
printf("shashi:main:gst_object_unref:to unref the bus\n");
  gst_object_unref (bus);
printf("shashi:main:gst_element_set_state:to set as null\n");
  gst_element_set_state (pipeline, GST_STATE_NULL);
printf("shashi:main:gst_object_unref:to unref the pipeline\n");
  gst_object_unref (pipeline);
  return 0;
}
