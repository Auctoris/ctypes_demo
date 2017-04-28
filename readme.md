# Building

To build use:

g++ -c -fPIC foo.cpp -o foo.o
g++ -shared -W1,-soname,libfoo.so -o libfoo.so foo.o
