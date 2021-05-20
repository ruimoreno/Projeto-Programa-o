#make file example

CC = gcc #compiler
#CFLAGS = -Wall -std=c99 -O3
TARGET = projeto #target file name

all:
	$(CC) -o $(TARGET) projeto.c


clean:
	rm $(TARGET)