//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================



#include "Store.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main() {



    Store store;
    store.createInventory("data4movies.txt");
    store.createCustomers("data4customers.txt");
    store.createTransaction("data4commands.txt");
    store.displayInventory();
    store.displayCustomers();
    store.displayTransaction();
    return 0;
}
