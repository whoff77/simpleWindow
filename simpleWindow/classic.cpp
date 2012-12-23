// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
classic.cpp
*****************************************************************
Derived from DVD class. Sorts by Data and Actor.
****************************************************************/

#include "stdafx.h"
#include "classic.h"

Classic::Classic() : Dvd() {}

Classic::~Classic() {}

bool Classic::populate(ifstream &infile) {
	infile.get();
	getline(infile, director, ',');
	infile.get();
	getline(infile, title, ',');
	infile >> actorFirst >> actorLast >> month >> year >>
		      copiesTotal >> copiesAvail;
	return true;
}

bool Classic::transPop(ifstream &infile) {
	infile >> month >> year >> actorFirst >> actorLast;
	return true;
}

bool Classic::operator==(const Movie &m) const {
	const Classic &c = static_cast<const Classic &>(m);
	return (year == c.year && month == c.month &&
			actorFirst == c.actorFirst && actorLast == c.actorLast);
}

bool Classic::operator!=(const Movie &m) const {
	const Classic &c = static_cast<const Classic &>(m);
	return (year != c.year || month != c.month ||
			actorFirst != c.actorFirst || actorLast != c.actorLast);
}

bool Classic::operator<(const Movie &m) const {
	const Classic &c = static_cast<const Classic &>(m);
	return (year < c.year || (year == c.year &&
		   (month < c.month || (month == c.month &&
		   (actorFirst < c.actorFirst || (actorFirst == c.actorFirst &&
		   (actorLast < c.actorLast)))))));
}
