//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef BINTREE_H
#define BINTREE_H

#include "Movie.h"

using namespace std;

//container to hold movies from the store by genre
class BinTree
{
    //friend operator to return tree elements in order
    friend ostream& operator<<(ostream&, const BinTree &bst);
    struct Node;

public:

    //constructor and deconstructor
    BinTree();
    BinTree(const BinTree &bst);
    ~BinTree();

    //Functions used to modify BST
    bool insert(Movie*);
    bool insertRecursive(Movie* rhs, Node &n);
    bool isEmpty() const; // true if tree is empty, otherwise false
    void makeEmpty(); // make the tree empty so isEmpty returns true
    bool retrieve(const Movie& dataItem, Movie*& dataFound) const;
    bool retrieveHelper(const Movie &rhs, Movie* &movie, Node &n) const;
    void printTree(std::ostream &out, Node *n);
    void displayInt(std::ostream &out);

    Node *root;

private:

    struct Node
    {
        Movie *movieInfo;
        Node *leftChildPtr;
        Node *rightChildPtr;
    };

    void destroyTree(Node*&);

    Node* newNode(Movie *movie);
};


#endif
