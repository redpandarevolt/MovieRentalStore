//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "Store.h"

//=================================================================
//Constructor and deconstructor
//=================================================================

Store::Store() {

    customers = new HashTable();

}

Store::~Store() {

    emptyStore();
}


//=================================================================
//opens fie and reads in information to assign information in The
//line to respective variables for customer
//=================================================================
void Store::createCustomers(string fileName){

    ifstream inFile;
    inFile.open(fileName);

    if (inFile.is_open())
    {
        int id;
        std::string first;
        std::string last;
        while (inFile >> id >> first >> last)
        {
            Customer *cust = new Customer(id, last, first);
            customers->insertCustomer(*cust);
        }

        inFile.close();
    }
    else
    {
        cerr << "Could not open file." << endl;
    }
}

//=================================================================
//opens fie and reads in information to assign information in The
//line to respective variables for inventory
//=================================================================
void Store::createInventory(string fileName){

    ifstream inFile;
    inFile.open(fileName);

    if (inFile.is_open())
    {
        string movieData;
        while (getline(inFile, movieData))
        {
            Movie *m = MovieFactory::createMovie(movieData);
            if (m->getGenre() == "F")
            {

                if( comedies == NULL){
                    comedies = new BinTree();
                }
                comedies->insert(m);
            }
            else if (m->getGenre() == "D")
            {
                if( dramas == NULL){
                    dramas = new BinTree();
                }
                dramas->insert(m);
            }
            else if (m->getGenre() == "C")
            {
                if( classics == NULL){
                    classics = new BinTree();
                }
                classics->insert(m);

            }
            else
            {
                delete m;
                m = NULL;
            }
        }

        inFile.close();
    }
    else
    {
        cerr << "Could not open file." << endl;
    }

}

/*std::ostream &operator<<(std::ostream &output, const BinTree &bst)
{
    output << bst.getStock() << ", " << com.getTitle() << ", " << com.getDirector() << ", " << com.getYear() << std::endl;
    return output;
}*/


//=================================================================
//display inventory contents for the store
//=================================================================

void Store::displayInventory(){

    cout << "Comedies:" << endl;
    comedies->displayInt(cout);

   // cout << *comedies << endl;
    cout << "Drama:" << endl;
    dramas->displayInt(cout);
    cout << "Classics:" << endl;
    classics->displayInt(cout);
}

//=================================================================
//display customer list for the store
//=================================================================
void Store::displayCustomers(){
    cout << "Customers:" << endl;
    customers->printHashTable();
}

//=================================================================
//display transction contents for the store
//=================================================================
void Store::displayTransaction(){

    cout << "Customer Transaction: " << endl;

        while (!transaction.empty())
        {
            //std::cout << transaction.front() << " ";
            Transaction *trans = transaction.front();
            trans->printTransaction();
            transaction.pop();
        }
        std::cout << std::endl;

}

//=================================================================
//opens fie and reads in information to assign information in The
//line to respective variables for transactions
//=================================================================
void Store::createTransaction(string fileName)
{
    ifstream inFile;
    inFile.open(fileName);

    if (inFile.is_open())
    {
        string transData;
        while (getline(inFile, transData))
        {
            Transaction *trans = transactionFactory::createTransaction(transData);
            if (trans->getTransactionType() == "H" || trans->getTransactionType() == "I" ||
                    trans->getTransactionType() == "R" || trans->getTransactionType() == "B")
            {
                transaction.push(trans);
            }
            else
            {
                delete trans;
                trans = NULL;
            }
        }
        inFile.close();
    }
    else
    {
        cerr << "Could not open file." << endl;
    }
}

//=================================================================
// retrieves hashtable where the customers are inserted
//=================================================================

HashTable& Store::getHashTable(){

    return *customers;
}

//=================================================================
//gets Drama, access private of in accessible variables
//=================================================================

BinTree& Store::getDrama(){
    return *dramas;
}


//=================================================================
// retrieves classics movies
//=================================================================

BinTree& Store::getClassics(){
    return *classics;
}

//=================================================================
//retrieves comedy movies
//=================================================================

BinTree& Store::getComedy(){
    return *comedies;
}


//=================================================================
//Clears out the store to create a new store object from incoming
//data as it is read in from the file
//=================================================================

void Store::emptyStore()
{
    movies.clear();
    getHashTable().makeEmpty();
    delete customers;
    getDrama().makeEmpty();
    delete dramas;
    getClassics().makeEmpty();
    delete classics;
    getComedy().makeEmpty();
    delete comedies;

    while (!transaction.empty())
    {
        delete transaction.front();
        transaction.pop();
    }
}

//=================================================================
//Method puts command into container via push
//=================================================================
void Store::addCommand(std::string str)
{
    Transaction *trans = transactionFactory::createTransaction(str);
    if (trans->getTransactionType() == "H" || trans->getTransactionType() == "I" ||
            trans->getTransactionType() == "R" || trans->getTransactionType() == "B")
    {
        transaction.push(trans);
    }
    else
    {
        delete trans;
        trans = NULL;
    }
}

//=================================================================
// moves transaction off the queue
//=================================================================
void Store::executeCommands()
{
    while (!transaction.empty())
    {
        Transaction *t = transaction.front();
        t->processTransaction(*this);
        delete transaction.front();
        transaction.pop();
    }
}
