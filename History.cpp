//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "History.h"

//=================================================================
//constructor and de-constructor
//=================================================================

History::History() {}

History::History(std::string str) {}

History::~History() {}

//=================================================================
//Process transaction gets customers from hash for print
//=================================================================

void History::processTransaction(Store &store){

    Customer *temp;
    if (store.getHashTable().retrieveCustomer(cid, temp))
    {
        temp->printHistory();
    }
    else
    {
        std::cerr << "ERROR: Wrong customer number: " << getCID() << endl;
    }

}
