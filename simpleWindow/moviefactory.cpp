// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
moviefactory.cpp
*****************************************************************
This class is called to designate movies to format types.
****************************************************************/

#include "stdafx.h"
#include "moviefactory.h"

MovieFactory::MovieFactory() {}

MovieFactory::~MovieFactory() {}

bool MovieFactory::create(char format, char genre, Movie *&m) {
	switch(format) {
	case 'D': // D = DVD
		return dFactory.create(genre, m);
	/* currently unused
	case 'B': // B = BLUERAY
		return bFactory.create(genre, infile, m);
	case 'V': // V = VHS TAPE
		return vFactory.create(genre, infile, m);
	*/
	default:
		cout << "ERROR: '" << format << "' is an invalid movie format." << endl;
		return false;
	}
}
