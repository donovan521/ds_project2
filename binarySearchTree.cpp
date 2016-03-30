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


  if(z->leftChild == nullptr && z->rightChild == nullptr && z->parent == nullptr) { //is root
        z = nullptr;
        this->root = nullptr;
        numNodes--;
  }

  else if(z->leftChild == nullptr && z->rightChild == nullptr) { //is leaf
          if((z->parent->leftChild != nullptr && z->parent->leftChild->value) == (z->value)) { //node to be deleted is left child
              z->parent->leftChild = nullptr;
          }
          else { //leaf is right child
              z->parent->rightChild = nullptr;
          }

      z = nullptr;
      numNodes--;
  }
  else if(z->leftChild == nullptr && z->rightChild != nullptr) { //case 1~

    if (z->rightChild->leftChild != nullptr) { // replace z with q
    Node * q = treeMinimum(z->rightChild);
    cout << "in delete" << q->rightChild << endl;
    q->parent->leftChild = nullptr;
    q->rightChild = z->rightChild;
    //q->leftChild =z->leftChild;
   // ((q->rightChild)->parent) = q;
   // q->leftChild = z->leftChild;
    z->parent->rightChild = q;
    if (q != nullptr)
    q->parent = z->parent;
    }
    /*
    else { //z only has right children
        cout << "in our case" << endl;
        //transplant z and z.right
        z->rightChild->parent = z->parent;
        z->parent->rightChild = z->rightChild;
      //  z = nullptr;
    }
    */

    /*
      if (z->rightChild->leftChild != nullptr) {
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
    */
      else { //z only has right children
          Transplant(z,z->rightChild);
         // z->parent->rightChild = z->rightChild;
         // z->rightChild->parent = z->parent;
         // z->parent = nullptr;
        //   z->rightChild = nullptr;
      }

    numNodes--;
  }
  else if (z->rightChild == nullptr) {//case 2
    Transplant(z,z->leftChild);
  numNodes--;
  }
  else{  //case 3 or 4
    Node * y = treeMinimum(z->rightChild);
     if(y->parent != z){
       Transplant(y,y->rightChild);
       y->rightChild = z->rightChild;
       ((y->rightChild)->parent) = y;
     }
   Transplant(z,y);
   y->leftChild = z->leftChild;
   ((y->leftChild)->parent) = y; 
   numNodes--;
      }
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
