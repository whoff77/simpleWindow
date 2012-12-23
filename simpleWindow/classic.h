// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
classic.h
*****************************************************************
Derived from DVD class. Sorts by Data and Actor.
****************************************************************/

#ifndef CLASSIC
#define CLASSIC

#include "dvd.h"

// ----- DERIVED CLASS Classic -------------------------------------------
class Classic : public Dvd {
	
public:
	Classic(); // default/blank constructor
	Classic(ifstream &); // data constructor
	//Classic(const Classic &); // copy constructor
	~Classic(); // destructor
	virtual bool populate(ifstream &);
	virtual bool transPop(ifstream &);
	virtual bool operator==(const Movie &) const;
	virtual bool operator!=(const Movie &) const;
	virtual bool operator<(const Movie &) const;

};

#endif
