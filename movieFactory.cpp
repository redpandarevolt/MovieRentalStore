//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "movieFactory.h"

//=================================================================
// constructor and destructor for movie processing per their
// char genre designation and process accordingly
//=================================================================

MovieFactory::MovieFactory() {}

MovieFactory::~MovieFactory() {}


//=================================================================
// switches to correct create method from the factory methods
//=================================================================
Movie* MovieFactory::createMovie(std::string str)
{
    if (str[0] == 'F') {
        return new Comedy(str);
    }

    else if (str[0] == 'D') {
        return new Drama(str);
    }

    else if (str[0] == 'C') {
        return new Classics(str);
    }

    else {

        std::cerr << "Invalid Selection: No such type of movie!" << std::endl;
        return new Movie();
    }
}
