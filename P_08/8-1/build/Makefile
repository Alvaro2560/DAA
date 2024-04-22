CC=g++
CXXFLAGS=-g -std=c++17 -Wall

OBJS = ../src/main.o ../src/greedy.o ../src/solution.o ../src/problem.o ../src/local-search.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p08 ${OBJS}
	mv ../src/*.o ../obj

clean:
	rm -rf ../obj/*.o p08