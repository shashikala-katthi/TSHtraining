
->To build the tutorials

gcc playback-tutorial-1.c -o playback-tutorial-1 `pkg-config --cflags --libs gstreamer-1.0`

->To run the tutorials

./playback-tutorial-1



->To build the tutorial 3
 
gcc playback-tutorial-3.c -o playback-tutorial-3 `pkg-config --cflags --libs gstreamer-1.0 gstreamer-audio-1.0`



->To build the tutorial 5

gcc playback-tutorial-5.c -o playback-tutorial-5 `pkg-config --cflags --libs gstreamer-1.0 gstreamer-video-1.0`

