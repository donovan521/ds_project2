CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 -O0 -pedantic-errors $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: p2

p2: p2.o node.o binarySearchTree.o	
	$(CC) $(LFLAGS) -o p2 p2.o node.o binarySearchTree.o

binarySearchTree.o: binarySearchTree.cpp	
	$(CC) $(CFLAGS)	binarySearchTree.cpp

node.o: node.cpp	
	$(CC) $(CFLAGS)	node.cpp

p2.o: p2.cpp	
	$(CC) $(CFLAGS)	p2.cpp

clean:
	rm -rf p2
	rm -rf *.o	
  	
run:
	./p2 input.txt
  
