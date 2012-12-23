// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
dvdfactory.h
*****************************************************************
This class is called to create movies of different genres from
movie objects that have been designated Dvd's.
****************************************************************/

#ifndef DVDFACTORY
#define DVDFACTORY

#include "classic.h"
#include "comedy.h"
#include "drama.h"

class DvdFactory {

public:
	DvdFactory();
	~DvdFactory();
	bool create(char, Movie*&);
};

#endif
