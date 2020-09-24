//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_HISTORY_H
#define MOVIE_HISTORY_H


#include "Store.h"


using namespace std;

class History: public Transaction {

public:

    //customer and de-constructor
    History();
    History(std::string str);
    virtual ~History();

    //processes transactions
    void processTransaction(Store&);


private:

};


#endif //MOVIE_HISTORY_H
