#!/bin/bash
g++ -L../../lib/linuxfltk-1.3.4-2/lib -L/usr/lib/x86_64-linux-gnu -o "exe/start"  o/start.o o/Window.o o/Simple_window.o o/GUI.o o/Graph.o  -lfltk -lfltk_images -lfltk_png -lfltk_z -lfltk_jpeg -lXft -lfontconfig -lXrender -lXfixes -lXext -lpthread -ldl -lm -lX11
echo "The command exited with status $?. Press Enter to close the terminal."
read line
