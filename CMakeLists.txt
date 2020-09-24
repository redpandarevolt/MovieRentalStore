cmake_minimum_required(VERSION 3.13)
project(Movie)

set(CMAKE_CXX_STANDARD 14)

add_executable(Movie main.cpp Movie.cpp Movie.h Classics.cpp Classics.h Comedy.cpp Comedy.h Drama.cpp Drama.h Transaction.cpp Transaction.h Return.cpp Return.h Borrow.cpp Borrow.h Inventory.cpp Inventory.h History.cpp History.h Store.cpp Store.h Customer.cpp Customer.h movieFactory.cpp movieFactory.h transactionFactory.cpp transactionFactory.h BinTree.cpp BinTree.h HashTable.cpp HashTable.h)