//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

//

#include "Comedy.h"

//=================================================================
//constructor and destructor for Comedy, derived class of Movie
//=================================================================
Comedy::Comedy(const string &title, int year){
    setTitle(title);
    setYear(year);
}

Comedy::Comedy(std::string str)
{
    movieStorage(str);
    setMovie();
}


Comedy::~Comedy(){}



//=================================================================
// assignment operators
//=================================================================


bool Comedy::operator==(const Movie& rhs) const{

    return (getTitle() == rhs.getTitle() && getYear() == rhs.getYear());
}
bool Comedy::operator!=(const Movie &rhs) const{
    return !(rhs == *this);
}


//=================================================================
//Relational operators will be use for sorting
//=================================================================

bool Comedy::operator<(const Movie &rhs) const{
    if (getTitle() == rhs.getTitle())
    {
        return (getYear()<rhs.getYear());
    }
    else
    {
        return(getTitle() < rhs.getTitle());
    }

}

bool Comedy::operator>(const Movie &rhs) const{
    return rhs < *this;
}

bool Comedy::operator<=(const Movie &rhs) const{
    return !(rhs < *this);
}

bool Comedy::operator>=(const Movie &rhs) const{
    return !(*this < rhs);
}


//=================================================================
//ostream to bring in movie information for display
//=================================================================
std::ostream &operator<<(std::ostream &output, Comedy &com)
{
    output << com.getStock() << ", " << com.getTitle() << ", " << com.getDirector() << ", " << com.getYear() << std::endl;
    return output;
}



