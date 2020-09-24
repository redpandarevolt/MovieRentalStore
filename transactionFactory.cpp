//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "transactionFactory.h"


//=================================================================
//Constructor and deconstructor
//=================================================================
transactionFactory::transactionFactory() {}

transactionFactory::~transactionFactory() {}


//=================================================================
//Factory method to process each specific type of transaction
//=================================================================
Transaction* transactionFactory::createTransaction(string str) {
    if (str[0] == 'I')  {
        return new Inventory(str);
    }

    else if (str[0] == 'H') {
        return new History(str);
    }

    else if (str[0] == 'B') {
        return new Borrow(str);
    }

    else if (str[0] == 'R') {
        return new Return(str);
    }

    else {
        std::cerr << "Invalid transaction type: " << str[0] << endl;
        return new Transaction();
    }
}
