// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
drama.h
*****************************************************************
Derived from DVD class. Sorts by Title and Year.
****************************************************************/

#ifndef DRAMA
#define DRAMA

#include "dvd.h"

// ----- DERIVED CLASS Drama -------------------------------------------
class Drama : public Dvd {

public:
	Drama(); // default/blank constructor
	Drama(ifstream &); // data constructor
	//Drama(const Drama &); // copy constructor
	~Drama(); // destructor
	//virtual bool populate(string);
	virtual bool transPop(ifstream &);
	virtual bool operator==(const Movie &) const;
	virtual bool operator!=(const Movie &) const;
	virtual bool operator<(const Movie &) const;
};

#endif
