// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
transaction.cpp
*****************************************************************
Base class for transactions that can be added to a customer's
history. All the customer/movie data is handled in this class.
****************************************************************/

#include "stdafx.h"
#include "transaction.h"
#include <sstream>	

Transaction::Transaction() {}

Transaction::Transaction(ifstream &infile, Formats *formatList) {
	mov = NULL;
	valid = generateCommand(infile, formatList);
}

Transaction::~Transaction() { mov = NULL; }

bool Transaction::generateCommand(ifstream &infile, Formats
								  *formatList) {
	infile >> format >> genre;
	if (!movFactory.create(format, genre, mov)) return false;
	if (!mov->transPop(infile)) return false;
	if (!formatList->getMovie(format, genre, mov)) {
		delete mov;
		return false;
	}
	return true;
}

void Transaction::executeCommand() { return; }

ostream& operator<<(ostream &output, const Transaction &t) {
	output << t.format << " " << t.type << " " << left <<
		setw(22) << t.mov->title.substr(0, 20) << left <<
		setw(17) << t.mov->director.substr(0,16) << t.mov->year;
	if (t.mov->month > 0) output << " " << right << setw(2) <<
		t.mov->month << "  " << t.mov->actorFirst << " " <<
		t.mov->actorLast;
	output << endl;
	return output;
}

string Transaction::stringTransaction() {
	std::stringstream ss;
	ss << format << " " << type << " " << mov->title << " " <<
		mov->director << " " << mov->year;
	if (mov->month > 0) ss << " " << mov->month << " " <<
		mov->actorFirst << " " << mov->actorLast;
	return ss.str();
}