//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_HASHTABLE_H
#define MOVIE_HASHTABLE_H

#include "Customer.h"
using namespace std;


#define MIN_TABLE_SIZE 2003
#define R 7

class HashTable
{
public:


    //=================================================================
    // constructor and de-constructor
    //=================================================================
    HashTable();
    ~HashTable();


    //=================================================================
    //Inserts a customer into table, returns true if succeeded.
    //=================================================================

    bool insertCustomer(Customer &cust);


    //=================================================================
    //Retrieves a customer from table, points to it.
    //=================================================================

    bool retrieveCustomer(int custID, Customer* &retC);

    //=================================================================
    //Returns true if no items are in the table
    //=================================================================
    bool isEmpty();


    //=================================================================
    //Prints out the table
    //=================================================================

    void printHashTable();

    void makeEmpty();

private:

    int size;
    Customer *customers[MIN_TABLE_SIZE];
    int hash1(int custID);
    int hash2(int custID);
};


#endif //MOVIE_HASHTABLE_H
