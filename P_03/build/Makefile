CC=g++
CXXFLAGS=-g -std=c++17

OBJS = ../src/main.o ../src/functions.o ../src/ram.o ../src/output-unit.o ../src/input-unit.o ../src/instructions.o ../src/debugger.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o ram ${OBJS}
	mv ../src/*.o ../obj

clean:
	rm -rf ../obj/*.o ram