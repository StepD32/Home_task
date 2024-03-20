CC = gcc
CFLAGS = -g -std=c99 -Wall
all: prog

prog: main.o temp_functions.o temp_functions_node.o
	$(CC) $(CFLAGS) -o prog main.o temp_functions.o temp_functions_node.o

main.o: main.c temp_functions.h temp_functions_node.h
	$(CC) $(CFLAGS) -c -o main.o main.c

temp_functions.o: temp_functions.c temp_functions.h
	$(CC) $(CFLAGS) -c -o temp_functions.o temp_functions.c

temp_functions_node.o: temp_functions_node.c temp_functions_node.h
	$(CC) $(CFLAGS) -c -o temp_functions_node.o temp_functions_node.c

clean:
	del /f *.o prog.exe