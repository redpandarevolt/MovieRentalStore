//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================
//Base Class Movie: holds constructor,  virtual deconstructor
// and all the assignment and relational operators to create a
// movie object.
//================================================================
#ifndef MOVIE_MOVIE_H
#define MOVIE_MOVIE_H

#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Movie {

    friend::ostream &operator<<(ostream &output, const Movie &mov);

public:

    //Default and parameterized constructor
    Movie(char genre, int stock, string director,
          string title, int year);
    Movie();
    //Movie(char genre, int stock, string director, string title, int year);

    // virtual constructor to hand super class
    virtual ~Movie();


    // Assignment Operator will be use for sorting
    virtual bool operator==(const Movie &rhs) const;
    virtual bool operator!=(const Movie &rhs) const;

    //Relational operators will be use for sorting
    virtual bool operator<(const Movie &rhs) const;
    virtual bool operator>(const Movie &rhs) const;

    //display of movie
    virtual void printMovie() const;
    virtual void columnHeadings() const;
    //virtual void setData(istream& infile);


    //Getter private variable to facilitate access

   /* string setMediatype();
    string getMediaType();*/


    string getDirector()const;
    //string getActorFirstName() const;
    //string getActorLastName() const;
    string getGenre() const;
    int getStock() const;
    string getTitle()const;
    int getYear() const;

    //void setActorFirstName(const string &actorFirstName);
    //void setActorLastName(const string &actorLastName);
    bool setDirector(string name);
    bool setTitle (string  newTitle);
    void setGenre(string genre);
    bool setStock(int stock);
    virtual void setMovie();
    bool setYear(int y);
    int getMonth() const;
    bool setMonth(int m);

    bool adjustStock(int s);
    void movieStorage(string line);
    std::string getMajorActor() const;
    //bool setMajorActor(std::string first, std::string last);


protected:

    std::string genre;
    int stock;
    int month;
    int year;
    std::string director;
    string majorActorName;
    string title;

    string majorActorFirst, majorActorLast;

    std::vector<std::string> movieData;
};


#endif //MOVIE_MOVIE_H
