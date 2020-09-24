//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "Inventory.h"

//=================================================================
// constructor and destructor for inventory types
//=================================================================

Inventory::Inventory() {}

Inventory::Inventory(std::string line) :Transaction(line) {}

Inventory::~Inventory() {}

void Inventory::processTransaction(Store &store)
{
    store.displayInventory();
}
