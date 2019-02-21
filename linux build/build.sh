#!/bin/bash
echo "Compiling..."
g++ -I../../lib/linuxfltk-1.3.4-2 -O3 -g3 -c -fmessage-length=0 "../src/start.cpp" -o "o/start.o" -std=c++11


g++ -L../../lib/linuxfltk-1.3.4-2/lib -L/usr/lib/x86_64-linux-gnu -o "exe/start"  o/hi.o o/Window.o o/Simple_window.o o/GUI.o o/Graph.o  -lfltk -lfltk_images -lfltk_png -lfltk_z -lfltk_jpeg -lXft -lfontconfig -lXrender -lXfixes -lXext -lpthread -ldl -lm -lX11
cd exe
./run.sh
echo "The command exited with status $?. Press Enter to close the terminal."
read line

