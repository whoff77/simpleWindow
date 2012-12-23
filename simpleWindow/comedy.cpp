// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
comedy.cpp
*****************************************************************
Derived from DVD class. Sorts by Title and Year.
****************************************************************/

#include "stdafx.h"
#include "comedy.h"

Comedy::Comedy() : Dvd() {}

//Comedy::Comedy(ifstream &infile) : Dvd(infile) {}

Comedy::~Comedy() {}

//bool Comedy::populate(string data) {}

bool Comedy::transPop(ifstream &infile) {
	infile.get();
	getline(infile, title, ',');
	infile >> year;
	return true;
}

bool Comedy::operator==(const Movie &m) const {
	const Comedy &f = static_cast<const Comedy &>(m);
	return (title == f.title && year == f.year);
}

bool Comedy::operator!=(const Movie &m) const {
	const Comedy &f = static_cast<const Comedy &>(m);
	return (title != f.title || year != f.year);
}

bool Comedy::operator<(const Movie &m) const {
	const Comedy &f = static_cast<const Comedy &>(m);
	return (title < f.title ||
		   (title == f.title && (year < f.year)));
}
