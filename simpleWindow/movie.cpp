// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
movie.cpp
*****************************************************************
Base class for Dvd objects (and any other formats added in the
future). Holds the movie data (title, director, etc) as well as
number of copies total/available. Public methods to add/subtract
from available copies.
****************************************************************/

#include "stdafx.h"
#include "movie.h"

Movie::Movie() {
	// copiesTotal = copiesAvail = 10;
	title = "";
	director = "";
	year = 0;
	month = 0;
	actorFirst = "";
	actorLast = "";
}

Movie::~Movie() {}

bool Movie::transPop(ifstream &infile) { return true; }
bool Movie::operator==(const Movie &) const { return true; }
bool Movie::operator!=(const Movie &) const { return true; }
bool Movie::operator<(const Movie &) const { return true; }

bool Movie::populate(ifstream &infile) {
	infile.get();
	getline(infile, director, ',');
	infile.get();
	getline(infile, title, ',');
	infile >> year >> copiesTotal >> copiesAvail;
	//infile >> actorFirst >> actorLast;
	return true;
}

/*
void Movie::printMovie() const {
	cout << right << setw(2) << copiesAvail << " " <<
			right << setw(2) << copiesTotal - copiesAvail << "  " <<
			left << setw(22) << title.substr(0, 20) << left <<
			setw(17) << director.substr(0,16) << year << " ";
	if (month > 0) cout << right << setw(2) << month << "  " <<
		actorFirst << " " << actorLast << " ";
	cout << endl;
}
*/

ostream& operator<<(ostream &output, const Movie &m) {
	output << right << setw(2) << m.copiesAvail << " " <<
			  right << setw(2) << m.copiesTotal - m.copiesAvail << "  " <<
			  left << setw(22) << m.title.substr(0, 20) << left <<
			  setw(17) << m.director.substr(0,16) << m.year << " ";
	if (m.month > 0) output << right << setw(2) << m.month << "  " <<
		m.actorFirst << " " << m.actorLast << " ";
	output << endl;
	return output;
}

bool Movie::saveMovie(char theFormat, char theGenre, ofstream &outfile) {
	outfile << theFormat << " " << theGenre << " " << director << ", " <<
		       title << ", ";
	if (month > 0)
		outfile << actorFirst << " " << actorLast << " " << month << " ";
	outfile << year << " " << copiesTotal << " " << copiesAvail << endl;
	return true;
}

//D C Michael Curtiz, Casablanca, Ingrid Bergman 8 1942 10 10
//string title, director, actorFirst, actorLast;
//int year, month, copiesTotal, copiesAvail;


void Movie::addTen() {
	copiesTotal += 10;
	copiesAvail += 10;
}

void Movie::decrement() {
	copiesAvail--;
}

void Movie::increment() {
	copiesAvail++;
}
