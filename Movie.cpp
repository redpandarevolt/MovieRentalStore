//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "Movie.h"

//=================================================================
//constructor and de-constructor and copy constructor
//=================================================================
Movie::Movie() {}

Movie::Movie(char movieType, int s, std::string directorName,
             std::string mt, int releaseYear)
{
    genre = movieType;
    stock = s;
    director = directorName;
    title = mt;
    year = releaseYear;
}

Movie::~Movie() {
    movieData.clear();
}


//=================================================================
//display methods have headings for the movies
//=================================================================

void Movie::columnHeadings() const{
    cout << "Genre" << " Stock" << " Director   " << " Title        " << year<< endl;
}

//=================================================================
//print movie
//=================================================================
void Movie::printMovie() const{
    cout << genre << " " << stock << " " << director << " " << title << " " << year << endl;
}


//=================================================================
//puts all the movies in queue
//=================================================================
void Movie::movieStorage(string line)
{
    std::string delimiter = ", ";
    std::string delimiter2 = "\n";
    size_t pos = 0;

    std::string token;

    while ((pos = line.find(delimiter)) != std::string::npos || (pos = line.find(delimiter2)) != std::string::npos)
    {
        token = line.substr(0, pos);
        movieData.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    movieData.push_back(line);
}


//=================================================================
//getters and setters for variables in the class
//=================================================================
string Movie::getGenre() const{

    return genre;
}

int Movie::getStock() const {
    return stock;
}



string Movie::getTitle()const{
    return title;
}


int Movie::getYear() const {
    return year;
}

//=================================================================
// Assignment Operator will be use for sorting
//=================================================================


bool Movie::operator==(const Movie &rhs) const {

    return (getDirector() == rhs.getDirector() && getTitle() == rhs.getTitle() && getYear() == rhs.getYear());

}
bool Movie::operator!=(const Movie &rhs) const {
    return !(rhs == *this);
}

//=================================================================
// relational operator less than and greater than
//=================================================================


bool Movie::operator<(const Movie &rhs) const {

    return (getYear()<rhs.getYear());
}

bool Movie::operator>(const Movie &rhs) const {

    return (getYear()>rhs.getYear());
}



//=================================================================
// remaining setters
//=================================================================
bool Movie::setTitle(string newTitle) {
    title = newTitle;
    return true;
}

bool Movie::setYear(int y) {

    year = y;
    return true;
}

void Movie::setGenre(string g) {
    genre = g;
}

string Movie::getDirector() const {
    return director;
}

bool Movie::setDirector(string name) {
    director = name;
}


//=================================================================
// adjusts stock when movies are borrowed and returned.
//=================================================================
bool Movie::setStock(int s) {

    if (s>= 0)
    {
        stock = s;
        return true;
    }
    return false;
}



void Movie::setMovie()
{

    setGenre(movieData[0]);
    setStock(stoi(movieData[1]));
    setDirector(movieData[2]);
    setTitle(movieData[3]);
    setYear(stoi(movieData[4]));

    /*movieData[0] = setGenre(genre);
    movieData[1] = setStock(stock);
    movieData[2]= setDirector(director);
    movieData[3] = setTitle(title);
    movieData[4] = setYear(year);*/
}

int Movie::getMonth() const {
    return month;
}

bool Movie::setMonth(int m)
{
    month = m;
    return true;
}



std::string Movie::getMajorActor() const
{
    return (majorActorName);
}


//=================================================================
//method adjusts stock for the transations return and borrow
//=================================================================
bool Movie::adjustStock(int s)
{
    if (s == 1)
    {
        stock += 1;
        return true;
    }
    else if (s==-1)
    {
        if (stock > 0)
        {
            stock -= 1;
            return true;
        }
        else
        {
            std::cerr << "This movie is currently out, pick another!" << std::endl;
            return false;
        }
    }
    else
    {
        return false;
    }
}



std::ostream &operator<<(std::ostream &output, const Movie &mov)
{
    //output << mov.getMovieType() << ", " << mov.getStock() << ", " << mov.getDirectorName() << ", " << mov.getTitle() << ", " << mov.getReleaseYear() << std::endl;
    return output;
}
