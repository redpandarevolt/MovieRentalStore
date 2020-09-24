//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "Classics.h"

//=================================================================
// constructor and deconstructor
//=================================================================

Classics::Classics(int month, int year, std::string majorActorFirstName, std::string majorActorLastName){

    setMonth(month);
    setYear(year);
    setMajorActor(majorActorFirstName, majorActorLastName);
}

Classics::Classics(std::string line){

    movieStorage(line);
    setMovie();

}

Classics::~Classics(){

}

//=================================================================
// assignment operators
//=================================================================
bool Classics::operator==(const Movie &rhs) const{

    return (getMonth() == rhs.getMonth() && getYear() == rhs.getYear() && getMajorActor() == rhs.getMajorActor());
}
bool Classics::operator!=(const Movie &rhs) const{

    return !(rhs == *this);
}


//=================================================================
// relational operator <
//=================================================================
bool Classics::operator<(const Movie &rhs) const{

    if (getYear() == rhs.getYear())
    {
        if (getMonth() == rhs.getMonth())
        {
            return getMajorActor() < rhs.getMajorActor();
        }
        else
        {
            return getMonth() < rhs.getMonth();
        }
    }
    else
    {
        return getYear() < rhs.getYear();
    }
}

//=================================================================
// relational operator >
//=================================================================
bool Classics::operator>(const Movie &rhs) const{
    return rhs < *this;
}


bool Classics::operator<=(const Movie &rhs) const{
    return !(rhs < *this);
}


bool Classics::operator>=(const Movie &rhs) const{
    return !(*this < rhs);
}

//=================================================================
// gets line from the file that came in and takes the data from the
// string without spaces and commas.
//=================================================================
void Classics::movieStorage(std::string line) {

    std::string delimiter = ", ";
    std::string delimiter2 = " ";
    size_t pos = 0;

    std::string token;

    while ((pos = line.find(delimiter)) != std::string::npos)
    {
        token = line.substr(0, pos);
        movieData.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    while ((pos = line.find(delimiter2)) != std::string::npos)
    {
        token = line.substr(0, pos);
        movieData.push_back(token);
        line.erase(0, pos + delimiter2.length());
    }
    movieData.push_back(line);
}

//=================================================================
//Getter private variable to facilitate access
//=================================================================
bool Classics::setMajorActor(std::string first, std::string last) {

    majorActorName = first + " " + last;
    return true;
}

/*int Classics::getMonth() {

    return month;
}*/

//=================================================================
// sets movie data for classic genre
//=================================================================

void Classics::setMovie()
{
    setGenre(movieData[0]);
    setStock(stoi(movieData[1]));
    setDirector(movieData[2]);
    setTitle(movieData[3]);
    setMajorActor(movieData[4], movieData[5]);
    setMonth(stoi(movieData[6]));
    setYear(stoi(movieData[7]));
}


//=================================================================
// operator to read in data from the file for all variables for
//the classic movie data
//=================================================================
std::ostream &operator<<(ostream &output, Classics & cm)
{
    output << cm.getGenre() << ", " << cm.getStock() << ", " << cm.getDirector() << ", " << cm.getTitle() <<
    ", " << cm.getMajorActor() << " " <<cm.getMonth() << " "<< cm.getYear() << std::endl;

    return output;
}



/*void Classics::display() const{
    cout << genre << " " << stock << " " << director << " " <<
         title << " " << firstName << " " << lastName << " " <<
         month << " " << year << endl;
}


void Classics::columnHeadings() const{
    cout << "Genre" << " Stock" << " Director   " <<
         " Title        " << "majorActor" << "releaseDate" << endl;
}

 Classics::Classics(istream& infile){

    string line;
    infile.getline(line);

    //Check if first char is 'C'
    infile.get();
    getline(infile, genre, ','); //this is char

    infile.get();
    getline(infile, stock, ','); // this is int

    infile.get();
    getline(infile, director, ','); //the rest are string

    infile.get();
    getline(infile, title, ',');

    infile.get();
    getline(infile, actorFirstName, " ");

    infile.get();
    getline(infile, actorLastName, ',');

    infile.get();
    infile >> year;

    setMovie();
}


 //git hub code to deal with mixed line or chars
 void Classics::splitLine(std::string line)
{
	std::string delimiter = ", ";
	std::string delimiter2 = " ";
	size_t pos = 0;

	std::string token;

	while ((pos = line.find(delimiter)) != std::string::pos)
	{
		token = line.substr(0, pos);
		mData.push_back(token);
		line.erase(0, pos + delimiter.length());
	}
	while ((pos = line.find(delimiter2)) != std::string::pos)
	{
		token = line.substr(0, pos);
		mData.push_back(token);
		line.erase(0, pos + delimiter2.length());
	}
	data.push_back(line);
}
 */
