//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_COMEDY_H
#define MOVIE_COMEDY_H

#include "Movie.h"

using namespace std;

class Comedy :  public Movie {

    friend::std::ostream &operator<<(std::ostream &output, Comedy &com);

public:

    //constructor and deconstructor
    Comedy(std::string str);
    Comedy(const string &title, int year);
    virtual ~Comedy();


    // assignment operators
    virtual bool operator==(const Movie& rhs) const;
    virtual bool operator!=(const Movie& rhs) const;

    //Relational operators will be use for sorting
    virtual bool operator<(const Movie& rhs) const;
    virtual bool operator>(const Movie& rhs) const;
    virtual bool operator<=(const Movie& rhs) const;
    virtual bool operator>=(const Movie& rhs) const;

    //std::string toString();


};


#endif //MOVIE_COMEDY_H
