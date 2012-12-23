// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
drama.cpp
*****************************************************************
Derived from DVD class. Sorts by Director and Title.
****************************************************************/

#include "stdafx.h"
#include "drama.h"

Drama::Drama() : Dvd() {}

//Drama::Drama(ifstream &infile) : Dvd(infile) {}

Drama::~Drama() {}

//bool Drama::populate(string data) {}

bool Drama::transPop(ifstream &infile) {
	infile.get();
	getline(infile, director, ',');
	infile.get();
	getline(infile, title, ',');
	return true;
}

bool Drama::operator==(const Movie &m) const {
	const Drama &d = static_cast<const Drama &>(m);
	return (director == d.director && title == d.title);
}

bool Drama::operator!=(const Movie &m) const {
	const Drama &d = static_cast<const Drama &>(m);
	return (director != d.director || title != d.title);
}

bool Drama::operator<(const Movie &m) const {
	const Drama &d = static_cast<const Drama &>(m);
	return (director < d.director ||
		   (director == d.director && (title < d.title)));
}
