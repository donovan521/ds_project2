#include <string>
#include <iostream>
#include "node.h"
#include "binarySearchTree.h"

using namespace std;



/**
 * Constructors
 */
binarySearchTree::binarySearchTree(){
    root = nullptr;
}

binarySearchTree::binarySearchTree(Node * r){
    root = r;
    numNodes++;
}


/**
 * copy constructor
 */
binarySearchTree::binarySearchTree(const binarySearchTree & m){
  this->root = m.root;
}

/**
 * copy operator
 */

  binarySearchTree& binarySearchTree::operator = (const binarySearchTree & m){
      this->root = m.root;

      return *this;
}


void binarySearchTree::Insert(Node * n){
    //    if (this->root = nullptr){
      //      this->root = n;
       // }
        Node * x = this->root;
        Node * compare = nullptr;
        while ( x != nullptr) {
            compare = x;
            if (n->value < x->value) {
                x = x->leftChild;
            }
            else {
                x = x->rightChild;
            }


        }
        n->parent = compare;
            if (compare == nullptr) { //empty tree
                this->root = n;
                numNodes++;
            }
            else if (n->value < compare->value){
                compare->leftChild = n;
                numNodes++;
            }
            else if (n->value > compare->value) {
                compare->rightChild = n;
                numNodes++;
            }
            else if(n->value == compare->value){ 

            }

  }

/**
 * Destructor
 */
//Order::~Order(void){

//}

