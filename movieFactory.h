//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#ifndef MOVIE_MOVIEFACTORY_H
#define MOVIE_MOVIEFACTORY_H


#include "Movie.h"
#include "Drama.h"
#include "Classics.h"
#include "Comedy.h"

//Base class for all movie types in the store inventory
class MovieFactory  {

public:

    //constructor and destructor
    MovieFactory();
    ~MovieFactory();

    //create movie obj
    static Movie* createMovie(std::string str);

};


#endif //MOVIEFACTORY_H
