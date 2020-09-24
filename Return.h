//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_RETURN_H
#define MOVIE_RETURN_H

#include "Store.h"


class Return : public Transaction{

public:

    //constructor and destructor
    Return();
    Return(std::string line);
    ~Return();

    void processTransaction(Store& store);

private:

    Movie *m;

};


#endif //MOVIE_RETURN_H
