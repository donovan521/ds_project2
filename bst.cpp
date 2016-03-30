#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <string>
#include <sstream>
#include <algorithm>
#include <fcntl.h>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "node.h"
#include "binarySearchTree.h"

using namespace std;

void nope_out(const string & name) {
  perror(name.c_str());
  exit(EXIT_FAILURE);
} // nope_out

//tree height function
int Height(Node * n) {
        if (n == nullptr){
            return 0;
        }
        if (n->leftChild == nullptr && n->rightChild == nullptr) {
            return 0;
        }
        return (1 + max(Height(n->leftChild),Height(n->rightChild)));
}

int main(const int argc, const char * argv []) {

  if (argc != 2) {
    cout << "Usage: " << argv[0] << " FILE" << endl;
    exit(0);
  } // if
  string filename = argv[1];
  ifstream input(filename);
  int r =0,flag = 0,nIndex = 1;
  binarySearchTree mainTree;
  for(string stringIn; getline(input,stringIn);) { //go thru each line
    istringstream iss(stringIn);
    string uinput;
    while(getline(iss,uinput,' ')){
      if (flag==1){
	const int valN = stoi(uinput);
	if(r==0){
	  Node * root = new Node(valN);
	  mainTree.Insert(root);
	  r++;
	}
	else{
	  Node * treeNode = new Node(valN);
	  mainTree.Insert(treeNode);
	  nIndex++;
	}
	flag=0;
      }
      if(flag==2){
	int valN = stoi(uinput);
	mainTree.Delete(mainTree.treeSearch(mainTree.root,valN));
	flag=0;
      }
      if(uinput=="insert"){
	flag = 1;
      }
      if(uinput=="delete"){
        flag = 2;
      }


    }
  
}

 //print to console
  cout << "Number of nodes in the bst: " << mainTree.numNodes <<endl;

  cout << "Height of the bst: " << Height(mainTree.root) <<endl;

  cout << "Pre-order traversal: " << endl;
  mainTree.PreOrderTraversal(mainTree.root);

  cout << endl << "In-order traversal: " << endl;
  mainTree.InOrderTraversal(mainTree.root);

  cout << endl << "Post-order traversal: " << endl;
  mainTree.PostOrderTraversal(mainTree.root);
  cout << endl;

  return EXIT_SUCCESS;
} // main

