gcc -c main.c -o main.o -I../../include
gcc main.o ../../lib/chugine.so -framework GLUT -framework OpenGL -framework Cocoa -o main
