#!/bin/bash
echo "Compiling..."
g++ -I../../lib/linuxfltk-1.3.4-2 -O3 -g3 -c -fmessage-length=0 "../src/start.cpp" -o "o/start.o" -std=c++11
g++ -I../../lib/linuxfltk-1.3.4-2 -O3 -g3 -c -fmessage-length=0 "../src/Window.cpp" -o "o/Window.o" -std=c++11
g++ -I../../lib/linuxfltk-1.3.4-2 -O3 -g3 -c -fmessage-length=0 "../src/Simple_window.cpp" -o "o/Simple_window.o" -std=c++11
g++ -I../../lib/linuxfltk-1.3.4-2 -O3 -g3 -c -fmessage-length=0 "../src/GUI.cpp" -o "o/GUI.o" -std=c++11
g++ -I../../lib/linuxfltk-1.3.4-2 -O3 -g3 -c -fmessage-length=0 "../src/Graph.cpp" -o "o/Graph.o" -std=c++11

g++ -L../../lib/linuxfltk-1.3.4-2/lib -L/usr/lib/x86_64-linux-gnu -o "exe/start"  o/start.o o/Window.o o/Simple_window.o o/GUI.o o/Graph.o  -lfltk -lfltk_images -lfltk_png -lfltk_z -lfltk_jpeg -lXft -lfontconfig -lXrender -lXfixes -lXext -lpthread -ldl -lm -lX11
echo "The command exited with status $?. Press Enter to close the terminal."
read line

