CC=g++
CXXFLAGS=-g -std=c++17

OBJS = ../src/main.o ../src/functions.o ../src/algorithm.o ../src/mergesort.o ../src/quicksort.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o dyv ${OBJS}
	mv ../src/*.o ../obj

clean:
	rm -rf ../obj/*.o dyv