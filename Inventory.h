//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_INVENTORY_H
#define MOVIE_INVENTORY_H


#include "Store.h"

//derived class for inventory
class Inventory : public Transaction{
public:

    //constructor and destructor
    Inventory();
    Inventory(std::string str);
    virtual ~Inventory();

    //method processes store transactions
    void processTransaction(Store &store);

};


#endif //MOVIE_INVENTORY_H
