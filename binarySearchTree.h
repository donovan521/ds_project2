#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include <string>
#include "node.h"

using namespace std;

class binarySearchTree {
    public:
    int height; // or make method?
    int numNodes = 0; // or just make method?
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

    //traversals
    void PreOrderTraversal();

    void PostOrderTraversal();

    void InOrderTraversal();
};

#endif //_BINARYSEARCHTREE_H
