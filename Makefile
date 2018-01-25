CC=g++
CFLAGS=-pedantic -Wall -std=c++11
SOURCES= *cpp

all:
	$(CC) $(CFLAGS) $(SOURCES)
