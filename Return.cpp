//=================================================================
// CSS 343 Summer Quarter, Program 4
// Created by marcela gomez on 2019-08-13.
//Last Modified 2019-08-19
//=================================================================

#include "Return.h"

//=================================================================
// return constructor and destructor
//=================================================================
Return::Return(){
}

Return::~Return() {
    delete m;
}

//=================================================================
// method handles unexpected input in between wanted data from
//the string read in from the file setting delimiters for spaces,
// commas and end of line characters.
//=================================================================
Return::Return(std::string str) :Transaction(str)
{
    std::string delimiter = " ";
    std::string delimiter2 = ",";
    std::string delimiter3 = "\n";

    string majorActorFirst,majorActorLast;

    size_t pos = str.find(delimiter);

    str.erase(0, pos + delimiter.length());
    pos = str.find(delimiter);
    cid = stoi(str.substr(0, pos));

    str.erase(0, pos + delimiter.length());
    pos = str.find(delimiter);
    mediaType = str.substr(0, pos);

    str.erase(0, pos + delimiter.length());
    pos = str.find(delimiter);
    genre = str.substr(0, pos);

    if (mediaType == "D")
    {
        if (genre == "C")
        {
            str.erase(0, pos + delimiter.length());
            pos = str.find(delimiter);
            movieMonth = stoi(str.substr(0, pos));

            str.erase(0, pos + delimiter.length());
            pos = str.find(delimiter);
            movieYear = stoi(str.substr(0, pos));

            str.erase(0, pos + delimiter.length());
            pos = str.find(delimiter);
            majorActorFirst = str.substr(0, pos);

            str.erase(0, pos + delimiter.length());
            pos = str.find(delimiter);
            majorActorLast = str.substr(0, pos);

            m = new Classics(movieMonth, movieYear, majorActorFirst, majorActorLast);
        }
        else if (genre == "F")
        {
            str.erase(0, pos + delimiter.length());
            pos = str.find(delimiter2);
            movieTitle = str.substr(0, pos);

            str.erase(0, pos + delimiter2.length() + 1);
            pos = str.find(delimiter3);
            movieYear = stoi(str.substr(0, pos));

            m = new Comedy(movieTitle, movieYear);
        }

        else if (genre == "D")
        {
            str.erase(0, pos + delimiter.length());
            pos = str.find(delimiter2);
            director = str.substr(0, pos);

            str.erase(0, pos + delimiter2.length() + 1);
            pos = str.find(delimiter2);
            movieTitle = str.substr(0, pos);

            m = new Drama(director, movieTitle);
        }
        else
        {
            std::cerr << "ERROR: Wrong media type: " << mediaType << std::endl;
        }
    }
}

//=================================================================
// Method processes transaction and returns error statement
//accordingly for erroneous data.
//=================================================================
void Return::processTransaction(Store& store){

    Customer *tempCust;
    Movie *tempMovie;
    if (store.getHashTable().retrieveCustomer(cid, tempCust))
    {
        if (genre == "D")
        {
            if (store.getDrama().retrieve(*m, tempMovie))
            {
                if (tempMovie->adjustStock(1))
                {
                    tempCust->recordHistory(*this);
                }
            }
            else
            {
                std::cerr << "ERROR: Could not find movie!" << endl;
            }
        }
        else if (genre == "C")
        {
            if (store.getClassics().retrieve(*m, tempMovie))
            {
                if (tempMovie->adjustStock(1))
                {
                    tempCust->recordHistory(*this);
                }
            }
            else
            {
                std::cerr << "ERROR: Could not find movie!" << endl;
            }
        }
        else if (genre == "F")
        {
            if (store.getClassics().retrieve(*m, tempMovie))
            {
                if (tempMovie->adjustStock(1))
                {
                    tempCust->recordHistory(*this);
                }
            }
            else
            {
                std::cerr << "ERROR: Could not find movie!" << endl;
            }
        }
    }
    else
    {
        std::cerr << "Wrong command: " << transactionLine << std::endl;
    }
}

/*
Return::Return(std::string line): Transaction(line){{

        for(int line_no = 1; getline(line); ++line_no){

            std::stringstream ss(line);

            string genre;
            char  media,  trans;
            int cid, month, year;
            string title, actorFirstName, actorLastName;
            string director;

            ss >> media;

            if(media == "D") {

                ss >> genre;
                if( genre == "C"){
                    ss >> month;
                    ss >> year;
                    ss >> actorFirstName;
                    ss >> actorLastName;

                    m = new Classics(month, year, actorFirstName, actorLastName);

                }
                else if (genre == "F"){
                    ss >> title;
                    ss >> year;

                    m = new Comedy(title, year);
                }
                else if (genre == "D"){
                    ss >> director;
                    ss >> title;

                    m = new Drama(director, title);

                }
                else {
                    cerr << "Invalid Media Type " << media << endl;
                }
            }*/
