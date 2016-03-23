#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include <string>
#include "node.h"

using namespace std;

class binarySearchTree {
    public:
    int height; // or make method?
    int numNodes; // or just make method?
    Node * root;

    /**
    * "Default" Constructor
    */
    binarySearchTree();


    /**
    * Constructors
    */
    binarySearchTree(Node * r);

    /**
    * copy constructor
    */
    binarySearchTree(const binarySearchTree &);

    /**
    * copy operator
    */
    binarySearchTree & operator = (const binarySearchTree &);

    /**
    * Destructor
    */
    //~Node(void);

    //insert function
    void Insert(Node *);
};

#endif //_BINARYSEARCHTREE_H
