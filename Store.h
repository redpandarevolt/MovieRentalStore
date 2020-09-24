//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_STORE_H
#define MOVIE_STORE_H


#include "movieFactory.h"
#include "BinTree.h"
#include "HashTable.h"
#include "Transaction.h"
#include "transactionFactory.h"


#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Store {

    //friend ostream& operator<<(ostream&, const BinTree &bst);

public:

    //consturctors and de-constructors
    Store();
    virtual ~Store();

    //reads in information from the file and creates
    //each section of the store.
    void createCustomers(string fileName);
    void createInventory(string fileName);
    void createTransaction(string fileName);


    //Containers to hold movies and customers
    HashTable &getHashTable();
    BinTree &getDrama();
    BinTree &getClassics();
    BinTree &getComedy();

    //methods to perform commands
    void executeCommands();
    void addCommand(std::string str);

    // display methods for all store sections
    void displayInventory();
    void displayCustomers();
    void displayTransaction();
    //void columnHeadings();

private:

    vector<Movie> movies;
    BinTree *comedies = NULL;
    BinTree *dramas = NULL;
    BinTree *classics = NULL;
    HashTable *customers = NULL;

    queue<Transaction*> transaction;

    void emptyStore();


};


#endif //MOVIE_STORE_H
