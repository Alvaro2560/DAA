CC=g++
CXXFLAGS=-g -std=c++17 -Wall

OBJS = ../src/main.o ../src/problem.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p07 ${OBJS}
	mv ../src/*.o ../obj

clean:
	rm -rf ../obj/*.o p07