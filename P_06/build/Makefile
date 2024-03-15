CC=g++
CXXFLAGS=-g -std=c++17 -Wall

OBJS = ../src/main.o ../src/functions.o ../src/greedy-solver.o ../src/brute-force-solver.o ../src/dynamic-programming-solver.o ../src/graph.o ../src/node.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o tsp ${OBJS}
	mv ../src/*.o ../obj

clean:
	rm -rf ../obj/*.o tsp