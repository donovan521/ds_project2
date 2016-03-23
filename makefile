CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 -O0 -pedantic-errors $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main

main: main.o node.o binarySearchTree.o	
	$(CC) $(LFLAGS) -o main main.o node.o binarySearchTree.o

binarySearchTree.o: binarySearchTree.cpp	
	$(CC) $(CFLAGS)	binarySearchTree.cpp

node.o: node.cpp	
	$(CC) $(CFLAGS)	node.cpp

main.o: main.cpp	
	$(CC) $(CFLAGS)	main.cpp

clean:
	rm -rf main
	rm -rf *.o	
  	
run:
	./main input.txt
  
