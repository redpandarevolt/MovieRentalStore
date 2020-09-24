//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

//=======================================================================
//BST adapted from class textbook by Carrano and GeeksforGeeks.com
//Movies will be stored and accessed from BinTree utilizing
//insertion, retrieve and display functions
//=======================================================================


#include "BinTree.h"


//=======================================================================
// Default constructor creates empty BinarySearchTree
//=======================================================================
BinTree::BinTree() :root(nullptr) { }

//copy
BinTree::BinTree(const BinTree &bst) {

    *this = bst;
}

//=======================================================================
// Destructor using makeEmpty to destroy the entire tree
//=======================================================================

BinTree::~BinTree() {
    if (root != nullptr)
        makeEmpty();
}


//=======================================================================
// Returns whether the BST is empty
//=======================================================================

bool BinTree::isEmpty() const {
    return (root == nullptr);
}

//=======================================================================
// Inserts a new Node* into BST and makes that its data ptr, point to
// a NodeData*
//=======================================================================

bool BinTree::insert(Movie* rhs) {
    if (isEmpty())
    {
        root = newNode(rhs);
        return true;
    }
    else
    {
        return insertRecursive(rhs, *this->root);
    }
}

//=======================================================================
//
//=======================================================================

bool BinTree::insertRecursive(Movie* rhs, Node &n) {
    if (n.movieInfo == rhs) {
        return false;
    }
    else if (*rhs < *n.movieInfo) {

        if (n.leftChildPtr == nullptr) {

            n.leftChildPtr = newNode(rhs);
            return true;
        }
        return insertRecursive(rhs, *n.leftChildPtr);
    }
    else if (*rhs > *n.movieInfo) {
        if (n.rightChildPtr == nullptr) {

            n.rightChildPtr = newNode(rhs);
            return true;
        }
        return insertRecursive(rhs, *n.rightChildPtr);
    }
    return false;
}

//=======================================================================
// Destroy's the BST in recursive fashion
//=======================================================================

void BinTree::makeEmpty() {
    destroyTree(root); //destroy entire BST
}

//=======================================================================
//
//=======================================================================
void BinTree::destroyTree(Node *&n) {
    // postorder traversal
    if (n != nullptr)
    {
        destroyTree(n->leftChildPtr); //destroy left
        destroyTree(n->rightChildPtr); //destroy right

        delete n->movieInfo; //delete NodeData
        n->movieInfo = nullptr;
        delete n; //Delete Node
        n = nullptr;
    }
}

void BinTree::displayInt(std::ostream &out){

   printTree(out, this->root);

}

//=======================================================================
// Retreive gets movie from bin tree
//=======================================================================

bool BinTree::retrieve(const Movie &rhs, Movie* &movie) const
{
    if (isEmpty())
    {
        movie = nullptr;
        return false;
    }
    else
    {
        return retrieveHelper(rhs, movie, *this->root);
    }
}
//=======================================================================
//retrieve helper assists retrieval method
//=======================================================================

bool BinTree::retrieveHelper(const Movie &rhs, Movie* &movie, Node &n) const
{
    if (movie == nullptr)
    {
        movie = nullptr;
        return false;
    }
    if (rhs == *n.movieInfo)
    {
        movie = n.movieInfo;
        return true;
    }
    if (rhs < *n.movieInfo)
    {
        return retrieveHelper(rhs, movie, *n.leftChildPtr);
    }
    if (rhs > *n.movieInfo)
    {
        return retrieveHelper(rhs, movie, *n.rightChildPtr);
    }


    return false;
}

//=======================================================================
//  Displays the data from BST in order. Uses helper function
// in order display to recursively traverse tree and print data.
//=======================================================================

std::ostream &operator<<(ostream &output, BinTree &bst)
{
    if (!bst.isEmpty())
    {
        bst.printTree(output, bst.root);
    }
    return output;
}

//------------------------- printTree ----------------
//helper for operator <<
//displays data in order

//=======================================================================
//
//=======================================================================
void BinTree::printTree(std::ostream& output, Node *n)
{
    if (n == NULL)
    {
        return;
    }

    if (n->leftChildPtr != NULL)
    {
        printTree(output, n->leftChildPtr);
    }

    n->movieInfo->printMovie();

    if (n->rightChildPtr != NULL)
    {
        printTree(output, n->rightChildPtr);
    }

}


//=======================================================================
//
//=======================================================================
BinTree::Node* BinTree::newNode(Movie *movie)
{
    Node* insNode = new Node;
    insNode->movieInfo = movie;
    insNode->leftChildPtr = NULL;
    insNode->rightChildPtr = NULL;
    return insNode;
}
