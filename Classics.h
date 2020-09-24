//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_CLASSICS_H
#define MOVIE_CLASSICS_H

#include "Movie.h"

class Classics : public Movie {

    friend::std::ostream &operator<<(std::ostream &output, Classics &clas);

public:
    Classics(int month, int Year, std::string actorFirstName,
            std::string actorLastName);
    Classics(std::string str);
    virtual~Classics();

    //virtual void display() const;
    //virtual void columnHeadings() const;
    //virtual void setData(istream& infile);


    // assignment operators
    bool operator==(const Movie &rhs) const;
    bool operator!=(const Movie &rhs) const;

    //Relational operators will be use for sorting
    bool operator<(const Movie &rhs) const;
    bool operator>(const Movie &rhs) const;
    bool operator<=(const Movie &rhs) const;
    bool operator>=(const Movie &rhs) const;


    //Getter private variable to facilitate access
    bool setMajorActor(std::string first, std::string last);
    void movieStorage(std::string line);
    void setMovie();

    string majorActorFirst, majorActorLast;

};


#endif //MOVIE_CLASSICS_H
