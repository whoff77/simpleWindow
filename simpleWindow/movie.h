// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
movie.h
*****************************************************************
Base class for Dvd objects (and any other formats added in the
future). Holds the movie data (title, director, etc) as well as
number of copies total/available. Public methods to add/subtract
from available copies.
****************************************************************/

#ifndef MOVIE
#define MOVIE

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Movie {

	friend ostream& operator<<(ostream&, const Movie &);

protected:
	//int copiesTotal, copiesAvail;

public:
	Movie(); // default/blank constructor
	Movie(ifstream &); // data constructor
	//Movie(const Movie &); // copy constructor
	virtual ~Movie(); // destructor
	virtual bool populate(ifstream &);
	virtual bool transPop(ifstream &);
	virtual bool operator==(const Movie &) const;
	virtual bool operator!=(const Movie &) const;
	virtual bool operator<(const Movie &) const;
	void printMovie() const;

	bool saveMovie(char, char, ofstream &);

	void addTen();
	void decrement();
	void increment();

	string title, director, actorFirst, actorLast;
	int year, month, copiesTotal, copiesAvail;
};

#endif
