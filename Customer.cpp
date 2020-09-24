//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "Customer.h"

//=================================================================
// constructor and deconstructor
//=================================================================

Customer::Customer(int id, string lName, string fName){
    cid = id;
    lastName = lName;
    firstName = fName;
}

Customer::Customer() {
    cid = -1;
    lastName = "";
    firstName = "";
}

Customer::~Customer() {

}


//=================================================================
// puts history in a queue
//=================================================================
void Customer::recordHistory(const Transaction &trans)
{
    rentalHistory.push_back(trans);
}


//=================================================================
// getters and setters for all variables in the class.
//=================================================================
string Customer::getCustomerFirstName() const {
    return firstName;
}
string Customer::getCustomerLastName() const{
    return lastName;
}
int Customer::getCID()const{
    return cid;
}




//=================================================================
// getters and setters for all variables in the class.
//=================================================================
void Customer::printHistory() {
    if (rentalHistory.size() == 0) {

        std::cout << "Customer has no rental history for " << getCustomerFirstName() << " " << getCustomerLastName() << " (ID#: " << getCID() << ") found."<<std::endl;
        std::cout << "========================================================" << std::endl;
        std::cout << std::endl;
    }
    else {

        std::cout << getCustomerFirstName() << " " << getCustomerLastName() << "'s (ID#: " << getCID() << ")  rental history: "<<std::endl;
        for (int i = 0; i < rentalHistory.size(); i++)
        {
            rentalHistory[i].printTransaction();
        }
        std::cout << "=========================================================" << std::endl;
        std::cout << std::endl;
    }
}


//=================================================================
// prints customers for display
//=================================================================
void Customer::printCustomer(std::ostream& outStream) const {
    std::cout << getCID() << " " << getCustomerFirstName() << " " << getCustomerLastName() << " ";
}



//=================================================================
// overloaded operators: assignment and ostream
//=================================================================

bool Customer::operator==(const Customer &rhs) const {

    return (cid == rhs.cid && firstName == rhs.firstName && lastName == rhs.lastName);
}

bool Customer::operator!=(const Customer &rhs) const {

    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &output, const Customer &cust) {

    cust.printCustomer(output);
    return output;
}



//=================================================================
// getters and setters for all variables in the class.
//=================================================================
void Customer::setCid(int cid) {

    Customer::cid = cid;
}

void Customer::setLastName(const string &lastName) {

    Customer::lastName = lastName;
}

void Customer::setFirstName(const string &firstName) {

    Customer::firstName = firstName;
}




