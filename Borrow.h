//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_BORROW_H
#define MOVIE_BORROW_H

#include "Store.h"

class Borrow : public Transaction {

public:

    //constructor and destructor
    Borrow();
    Borrow(std::string line);
    virtual ~Borrow();

    // method to process transaction from the store
    void processTransaction(Store &store);

private:

    Movie *m;

 };


#endif //MOVIE_BORROW_H
