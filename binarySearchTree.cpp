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

Node * binarySearchTree::treeMinimum(Node * x){
  while(x->leftChild != nullptr)
    x = x->leftChild;
  return x;
}

void binarySearchTree::Transplant(Node * u , Node * v){

  if(u->parent == nullptr)
    this->root = v;
  else if (u == ((u->parent)->leftChild))
    ((u->parent)->leftChild) = v;
  else
    ((u->parent)->rightChild) = v;
  if (v != nullptr)
    v->parent = u->parent;

}

Node * binarySearchTree::treeSearch(Node * x, int k){
  if((x == nullptr) || (k == x->value))
    return x;
  if(k < (x->value))
    return treeSearch(x->leftChild,k);
  else
    return treeSearch(x->rightChild,k);
}

void binarySearchTree::Delete(Node * z){
  if(z != nullptr){
  if(z->leftChild == nullptr)
    Transplant(z,z->rightChild);
  else if (z->rightChild == nullptr)
    Transplant(z,z->leftChild);
  else{ 
    Node * y = treeMinimum(z->rightChild);
     if(y->parent != z){
       Transplant(y,y->rightChild);
       y->rightChild = z->rightChild;
       ((y->rightChild)->parent) = y;
     }
   Transplant(z,y);
   y->leftChild = z->leftChild;
   ((y->leftChild)->parent) = y; 
      }
  numNodes--;
  }
}

void binarySearchTree::Insert(Node * n){
    //    if (this->root = nullptr){
      //      this->root = n;
       // }
  if(treeSearch(this->root,n->value)==nullptr){
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
