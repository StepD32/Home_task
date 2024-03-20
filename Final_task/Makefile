CC = gcc
CFLAGS = -g -std=c99 -Wall
all: prog

prog: main.o temp_functions.o
	$(CC) $(CFLAGS) -o prog main.o temp_functions.o

main.o: main.c temp_functions.h
	$(CC) $(CFLAGS) -c -o main.o main.c

temp_api.o: temp_functions.c temp_functions.h
	$(CC) $(CFLAGS) -c -o temp_api.o temp_functions.c

clean:
	del /f *.o prog.exe