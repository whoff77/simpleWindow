// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
comedy.h
*****************************************************************
Derived from DVD class. Sorts by Title and Year.
****************************************************************/

#ifndef COMEDY
#define COMEDY

#include "dvd.h"

// ----- DERIVED CLASS Comedy -------------------------------------------
class Comedy : public Dvd {

public:
	Comedy(); // default/blank constructor
	Comedy(ifstream &); // data constructor
	//Comedy(const Comedy &); // copy constructor
	~Comedy(); // destructor
	//virtual bool populate(string);
	virtual bool transPop(ifstream &);
	virtual bool operator==(const Movie &) const;
	virtual bool operator!=(const Movie &) const;
	virtual bool operator<(const Movie &) const;
};

#endif
