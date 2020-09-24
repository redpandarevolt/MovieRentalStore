//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "HashTable.h"



//=================================================================
//contructor and de-constructor for hash table
//=================================================================

HashTable::HashTable() {

    size = 0;
    for (int i = 0; i < MIN_TABLE_SIZE; i++)
    {
        customers[i] = NULL;
    }
}

HashTable::~HashTable() {
    makeEmpty();
}


//=================================================================
//returns true if hash table is empty
//=================================================================

bool HashTable::isEmpty() {
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//=================================================================
//prints out the hashtable
//=================================================================

void HashTable::printHashTable() {
    if (isEmpty())
    {
        return;
    }
    else
    {
        for (int i = 0; i < MIN_TABLE_SIZE; i++)
        {
            if (customers[i] != NULL)
            {
                std::cout << *customers[i] << std::endl;
            }
        }
    }
}


//=================================================================
//returns first hash
//=================================================================

int HashTable::hash1(int custID) {
    return (custID % MIN_TABLE_SIZE);
}

//=================================================================
//returns second hash
//=================================================================

int HashTable::hash2(int custID) {
    return (R - (custID % R));
}

//=================================================================
//customer is intersted into hash table
//=================================================================
bool HashTable::insertCustomer(Customer &cust) {
    if (customers[hash1(cust.getCID())] == NULL)
    {
        int key1 = hash1(cust.getCID());
        customers[key1] = &cust;
        size++;
        return true;
    }
    else
    {
        for (int i = 1; i < MIN_TABLE_SIZE; i++)
        {
            if (customers[(hash1(cust.getCID()) + i*hash2(cust.getCID())) % MIN_TABLE_SIZE] == NULL)
            {
                customers[(hash1(cust.getCID()) + i*hash2(cust.getCID())) % MIN_TABLE_SIZE] = &cust;
                break;
            }
        }
        size++;
        return true;
    }
    return false;
}



//=================================================================
//Retrieves a customer from table, points to it.
//=================================================================

bool HashTable::retrieveCustomer( int custID, Customer* &retC) {
    for (int i = 0; i < MIN_TABLE_SIZE; i++) {
        if (customers[(hash1(custID) + i * hash2(custID)) % MIN_TABLE_SIZE] == NULL) {
            retC = NULL;
            return false;
        } else if (customers[(hash1(custID) + i * hash2(custID)) % MIN_TABLE_SIZE]->getCID() == custID) {
            retC = customers[(hash1(custID) + i * hash2(custID)) % MIN_TABLE_SIZE];
            return true;
        }
    }
}

//=================================================================
// removes everything in the table
//=================================================================
void HashTable::makeEmpty() {
    if (!isEmpty())
    {
        for (int i = 0; i < MIN_TABLE_SIZE; i++)
        {
            if (customers[i] != NULL)
            {
                delete customers[i];
                customers[i] = NULL;
                size--;
            }
        }
    }
}
