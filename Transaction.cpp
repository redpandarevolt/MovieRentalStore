//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "Transaction.h"

//=================================================================
//Constructor and deconstructor
//=================================================================
Transaction::Transaction(){}

Transaction::Transaction(std::string str) {

    transactionLine = str;
    transactionType = str[0];
}

Transaction::~Transaction(){}



//=================================================================
// checks transaction type and returns an error statement if The
// wrong type of tansaction is read in from the file
//=================================================================
bool Transaction::setTransactionType(string tType) {

    if (tType == "I" || tType == "H" || tType == "B" || tType == "R")
    {
        transactionType = tType;
        return true;
    }
    else
    {
        std::cerr << "The selection : " << tType << "is invalid, try again" << std::endl;
        return false;
    }
}


//=================================================================
//Set methods for all variables in th method: customer ID, Genre
//month, year, title, actor first name and last and director name
//=================================================================
bool Transaction::setCID(int id) {
    cid = id;
    return true;
}

void Transaction::setGenre(const string &genre) {
    Transaction::genre = genre;
}

void Transaction::setMediaType(const string &mediaType) {
    Transaction::mediaType = mediaType;
}

void Transaction::setMonth(int m) {
    movieMonth = m;
}

void Transaction::setMYear(int y)
{
    movieYear = y;
}

void Transaction::setTitle(std::string mTitle) {
    movieTitle = mTitle;
}

void Transaction::setActorFirstName(string fName) {

    actorFirstName = fName;
}

void Transaction::setActorLastName(string lName) {

    actorLastName = lName;
}

void Transaction::setDirector(std::string name) {
    director = name;
}


//=================================================================
//Set methods for all variables in th method: customer ID, Genre
//month, year, title, actor first name and last and director name
//=================================================================

//=================================================================
//Method to process transaction and display the results
//=================================================================
void Transaction::processTransaction(Store &store){}

void Transaction::printTransaction(){

    cout << transactionLine << endl;
}

//=================================================================
//Get methods for all variables in th method: customer ID, Genre
//month, year, title, actor first name and last and director name
//=================================================================
string Transaction::getTransactionType() const {

    return transactionType;
}


int Transaction::getCID() const {

    return cid;
}

string Transaction::getGenre() const {
    return genre;
}

string Transaction::getMediaType() const {
    return mediaType;
}

int Transaction::getMonth() const {

    return movieMonth;
}

int Transaction::getYear() const {
    return movieYear;
}

string Transaction::getTitle() const {
    return movieTitle;
}

string Transaction::getActorFirstName() const {
    return actorFirstName;
}

string Transaction::getActorLastName() const {
    return actorLastName;
}

string Transaction::getActorName() const
{
    return (actorFirstName + " " + actorLastName);
}

string Transaction::getDirector() const {

    return director;
}
