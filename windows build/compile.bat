call "E:\Program Files\VS\VC\Auxiliary\Build\vcvarsall.bat" x86
cl "../src/start.cpp" "../src/Window.cpp" "../src/Simple_window.cpp" "../src/GUI.cpp" "../src/Graph.cpp" /c /I../../lib/fltk-1.3.4-2 /MDd /EHsc
pause