// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
moviefactory.h
*****************************************************************
This class is called to designate movies to format types.
****************************************************************/

#ifndef MOVIEFACTORY
#define MOVIEFACTORY

#include "dvdfactory.h"

class MovieFactory {

public:
	MovieFactory();
	~MovieFactory();
	bool create(char, char, Movie*&);

private:
	DvdFactory dFactory;
};

#endif
