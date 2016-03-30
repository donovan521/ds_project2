CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 -O0 -pedantic-errors $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: bst

bst: bst.o node.o binarySearchTree.o	
	$(CC) $(LFLAGS) -o bst bst.o node.o binarySearchTree.o

binarySearchTree.o: binarySearchTree.cpp	
	$(CC) $(CFLAGS)	binarySearchTree.cpp

node.o: node.cpp	
	$(CC) $(CFLAGS)	node.cpp

bst.o: bst.cpp	
	$(CC) $(CFLAGS)	bst.cpp

clean:
	rm -rf bst
	rm -rf *.o	
  	
run:
	./bst test1.txt
  
