//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_DRAMA_H
#define MOVIE_DRAMA_H

#include "Movie.h"

using namespace std;


class Drama : public Movie {

public:


    //constructor and deconstructor
    Drama(char genre, int stock, string director, string title, int Year);
    Drama(string director,	string title);
    Drama(std::string str);
    ~Drama();


    // assignment operators
    bool operator==(const Movie &rhs) const;
    bool operator!=(const Movie &rhs) const;

    //Relational operators will be use for sorting
    bool operator<(const Movie& rhs) const;
    bool operator>(const Movie& rhs) const;
    bool operator<=(const Movie& rhs) const;
    bool operator>=(const Movie& rhs) const;

};


#endif //MOVIE_DRAMA_H
