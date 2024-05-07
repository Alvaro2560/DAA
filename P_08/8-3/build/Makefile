CC=g++
CXXFLAGS=-g -std=c++17 -Wall

OBJS = ../src/main.o ../src/greedy.o ../src/solution.o ../src/problem.o ../src/local-search.o ../src/grasp.o ../src/tabu-search.o ../src/branch-bound.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p08 ${OBJS}
	mv ../src/*.o ../obj

clean:
	rm -rf ../obj/*.o p08

clean-back:
	rm -rf ../src/*.o