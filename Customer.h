//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_CUSTOMER_H
#define MOVIE_CUSTOMER_H


#include <string>
#include <vector>

#include "Movie.h"
#include "Transaction.h"

using namespace std;

class Customer{

    friend::std::ostream &operator<<(std::ostream &output, const Customer &cust);

public:

    //constructor destructor
    Customer(int id, std::string lName, std::string fName);
    Customer();
    ~Customer();


    //get methods to access private data
    int getCID()const;
    string getCustomerLastName() const;
    string getCustomerFirstName() const;

    // sets data
    void setCid(int cid);
    void setLastName(const string &lastName);
    void setFirstName(const string &firstName);

    
    void recordHistory(const Transaction &trans);
    //bool returnMovie(Movie& rent);
    void printCustomer(std::ostream& outStream = std::cout) const;
    void printHistory();

    virtual bool operator==(const Customer &rhs) const;
    virtual bool operator!=(const Customer &rhs) const;

private:

    int cid;
    string lastName;
    string firstName;

    vector<Transaction> rentalHistory;
};


#endif //MOVIE_CUSTOMER_H
