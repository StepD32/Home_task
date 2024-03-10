CC = gcc
CFLAGS = -std=c99 -Wall
all: prog

prog: main.o temp_api.o
	$(CC) $(CFLAGS) -o prog main.o temp_api.o

main.o: main.c temp_api.h
	$(CC) $(CFLAGS) -c -o main.o main.c

temp_api.o: temp_api.c temp_api.h
	$(CC) $(CFLAGS) -c -o temp_api.o temp_api.c

clean:
	del /f *.o prog.exe