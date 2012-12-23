// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
dvdfactory.cpp
*****************************************************************
This class is called to create movies of different genres from
movie objects that have been designated Dvd's.
****************************************************************/

#include "stdafx.h"
#include "dvdfactory.h"

DvdFactory::DvdFactory() {}

DvdFactory::~DvdFactory() {}

bool DvdFactory::create(char genre, Movie *&d) {
	switch(genre) {
	case 'C':
		d = new Classic(/*infile*/);
		return true;
	case 'F':
		d = new Comedy(/*infile*/);
		return true;
	case 'D':
		d = new Drama(/*infile*/);
		return true;
	default:
		cout << "ERROR: '" << genre << "' is an invalid dvd genre." << endl;
		return false;
	}
}
