call "E:\Program Files\VS\VC\Auxiliary\Build\vcvarsall.bat" x86
cl "../src/start.cpp" "../src/Graph.cpp" "../src/Window.cpp"  "../src/GUI.cpp" /c /I../../lib/fltk-1.3.4-2  /MD /EHsc 
cl "start.obj" "Window.obj" "Graph.obj" "GUI.obj" /incremental /nologo  "E:\Projects\C++\FLTK projects\lib\fltk-1.3.4-2\lib\fltkimagesd.lib" "E:\Projects\C++\FLTK projects\lib\fltk-1.3.4-2\lib\fltkpngd.lib" "E:\Projects\C++\FLTK projects\lib\fltk-1.3.4-2\lib\fltkzlibd.lib" "E:\Projects\C++\FLTK projects\lib\fltk-1.3.4-2\lib\fltkjpegd.lib" "E:\Projects\C++\FLTK projects\lib\fltk-1.3.4-2\lib\fltkd.lib" KERNEL32.LIB USER32.LIB GDI32.LIB WINSPOOL.LIB COMDLG32.LIB ADVAPI32.LIB SHELL32.LIB OLE32.LIB OLEAUT32.LIB UUID.LIB ODBC32.LIB ODBCCP32.LIB /link /SUBSYSTEM:windows /ENTRY:mainCRTStartup
pause