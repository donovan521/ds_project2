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

void binarySearchTree::PreOrderTraversal(Node * r){
    cout << r->value << " ";

    if (r->leftChild != nullptr){
        PreOrderTraversal(r->leftChild);
    }

    if (r->rightChild != nullptr){
        PreOrderTraversal(r->rightChild);
    }
}

void binarySearchTree::PostOrderTraversal(Node * r){

    if (r->leftChild != nullptr){
        PostOrderTraversal(r->leftChild);
    }

    if (r->rightChild != nullptr){
        PostOrderTraversal(r->rightChild);
    }

    cout << r->value << " ";

}

void binarySearchTree::InOrderTraversal(Node * r){
    if (r->leftChild != nullptr){
        InOrderTraversal(r->leftChild);
    }

    cout << r->value << " ";

    if (r->rightChild != nullptr){
        InOrderTraversal(r->rightChild);
    }

}

/**
 * Destructor
 */
//Order::~Order(void){

//}

