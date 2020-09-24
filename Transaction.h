//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================
//================================================================
// Base Class Transaction - sub classes are borrow, return history
// Transaction is the sub class of the Store base class.
//================================================================

#ifndef MOVIE_TRANSACTION_H
#define MOVIE_TRANSACTION_H

#include <iostream>
#include <string>

using namespace std;

class Store;

class Transaction  {

public:

    //consturctors and de-constructors
    Transaction();
    Transaction(string str);
    virtual ~Transaction();

    //virtual methods to process and display transactions
    virtual void processTransaction(Store &store);
    virtual void printTransaction();

    //virtual bool setData(string media, Inventory * Item, Customer *cid );
    //Get methods for all protected members
    string getTransactionType() const;
    string getTransactionLine() const;
    int getCID() const;
    string getGenre() const;
    string getMediaType() const;
    int getMonth() const;
    int getYear() const;
    string getTitle() const;
    string getActorName() const;
    string getActorFirstName() const;
    string getActorLastName() const;
    string getDirector() const;



    //Set methods for all protected members
    bool setTransactionType(string tType);
    void setTransactionLine(const string &transactionLine);
    bool setCID(int id);
    void setGenre(const string &genre);
    void setMediaType(const string &mediaType);
    void setMonth(int m);
    void setMYear(int y);
    void setTitle(string mTitle);
    void setActorFirstName(string fName);
    void setActorLastName(string lName);
    void setDirector(string name);


protected:
    string transactionType;
    string transactionLine;
    int cid;
    string genre, mediaType;
    int movieMonth , movieYear;
    string movieTitle;
    string actorFirstName, actorLastName;
    string director;


};


#endif //MOVIE_TRANSACTION_H
