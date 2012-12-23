// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
dvd.h
*****************************************************************
Abstract class derived from Movie class, the base class of
Classic, Comedy, and Drama.
****************************************************************/

#ifndef DVD
#define DVD

#include "movie.h"

// ----- DERIVED CLASS Dvd -------------------------------------------
class Dvd : public Movie {

public:
	Dvd(); // default/blank constructor
	Dvd(ifstream &); // data constructor
	//Dvd(const Dvd &); // copy constructor
	virtual ~Dvd(); // destructor
	virtual bool operator==(const Movie &) const = 0;
	virtual bool operator!=(const Movie &) const = 0;
	virtual bool operator<(const Movie &) const = 0;
};

#endif
