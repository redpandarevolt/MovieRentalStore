//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_TRANSACTIONFACTORY_H
#define MOVIE_TRANSACTIONFACTORY_H

#include "Inventory.h"
#include "History.h"
#include "Borrow.h"
#include "Return.h"
#include <string>

using namespace std;

class transactionFactory {


public:

    //consturctors and de-constructors
    transactionFactory();
    ~transactionFactory();

    // transaction object created
    static Transaction* createTransaction(string str);
};


#endif //MOVIE_TRANSACTIONFACTORY_H
