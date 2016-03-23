#include <string>
#include <iostream>
#include "node.h"
#include "binarySearchTree.h"

using namespace std;



/**
 * Constructors
 */
binarySearchTree::binarySearchTree(Node * r){
    root = r;
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

/**
 * Destructor
 */
//Order::~Order(void){

//}

