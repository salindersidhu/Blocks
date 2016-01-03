# Makefile for compiling on a linux operating system
CC=g++
CFLAGS=-std=c++0x -c

all: Blocks

Blocks: Clock.o Grid.o Block.o tinyfiledialogs.o DialogManager.o PhyfsStream.o DrawManager.o Button.o LevelManager.o  BlocksGame.o Main.o
	$(CC) Clock.o Grid.o Block.o tinyfiledialogs.o DialogManager.o PhyfsStream.o DrawManager.o Button.o LevelManager.o BlocksGame.o Main.o -o Blocks

Clock.o:
	$(CC) $(CFLAGS) Clock.cpp

Grid.o:
	$(CC) $(CFLAGS) Grid.cpp

Block.o:
	$(CC) $(CFLAGS) Block.cpp

tinyfiledialogs.o:
	$(CC) $(CFLAGS) tinyfiledialogs.cpp

DialogManager.o:
	$(CC) $(CFLAGS) DialogManager.cpp

PhyfsStream.o:
	$(CC) $(CFLAGS) PhyfsStream.cpp

DrawManager.o:
	$(CC) $(CFLAGS) DrawManager.cpp

Button.o:
	$(CC) $(CFLAGS) Button.cpp

LevelManager.o:
	$(CC) $(CFLAGS) LevelManager.cpp

BlocksGame.o:
	$(CC) $(CFLAGS) BlocksGame.cpp

clean:
	rm -rf *o
