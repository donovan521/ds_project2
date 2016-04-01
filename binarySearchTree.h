#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include <string>
#include "node.h"

using namespace std;

class binarySearchTree {
    public:
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
    void printLevelOrder(int depth);
    string printLevel(Node * x, int level);
    //Transplant Function
    void Transplant(Node * u , Node * v);
    void Delete(Node * z);
    Node * treeSearch(Node * x, int k);
    //Minimum Function
    Node * treeMinimum(Node * x);
    //insert function
    void Insert(Node *);

    //traversals
    void PreOrderTraversal(Node *);

    void PostOrderTraversal(Node *);

    void InOrderTraversal(Node *);
};

#endif //_BINARYSEARCHTREE_H
