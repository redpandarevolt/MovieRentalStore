//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================
#include "Drama.h"



//=================================================================
// Constructor and de-constructor
//=================================================================
Drama::Drama(char genre, int stock, string director, string title, int year)
    :Movie(genre, stock, director, title, year){
}

Drama::Drama(string director, string title)
{
    setDirector(director);
    setTitle(title);
}


Drama::Drama(std::string str)
{
    movieStorage(str);
    setMovie();
}

Drama::~Drama(){}


//=================================================================
// assignment operators
//=================================================================

bool Drama::operator==(const Movie& rhs) const{

    return (getDirector() == rhs.getDirector() && getTitle() == rhs.getTitle());

}

bool Drama::operator!=(const Movie& rhs) const{
    return !(rhs == *this);
}


//=================================================================
// //Relational operators will be use for sorting
//=================================================================

bool Drama::operator<(const Movie& rhs) const{

    if (director == rhs.getDirector())
    {
        return title < rhs.getTitle();
    }
    else
    {
        return director < rhs.getDirector();
    }
}


bool Drama::operator>(const Movie& rhs) const{

    if (director == rhs.getDirector())
    {
        return title > rhs.getTitle();
    }
    else
    {
        return director > rhs.getDirector();
    }
    //return rhs < *this;
}


bool Drama::operator<=(const Movie& rhs) const{

    return !(rhs < *this);
}


bool Drama::operator>=(const Movie& rhs) const{

    return !(*this < rhs);
}
