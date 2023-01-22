OBJS = Stage.o Segment.o scd_rando_tracker.o
CC = g++
DEBUG = -g -ggdb
CFLAGS = $(DEBUG) -Wall -c
LFLAGS = $(DEBUG) -Wall

Main : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o scd_rando_tracker

Stage : Stage.h Stage.cpp
	$(CC) $(CFLAGS) Stage.cpp

Segment : Segment.h Segment.cpp
	$(CC) $(CFLAGS) Segment.cpp
	
clean:
	\rm *.o