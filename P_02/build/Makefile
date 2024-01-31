CC=g++
CXXFLAGS=-g -std=c++17 -Wall

OBJS = ../src/main.o ../src/functions.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o ram ${OBJS}
	mv ../src/*.o ../obj

clean:
	rm -rf ../obj/*.o ram