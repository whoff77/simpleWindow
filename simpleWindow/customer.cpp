// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
customer.cpp
*****************************************************************
This object represents one customer, with their name and id num,
as well as a pointer to their history of transactions.
****************************************************************/

#include "stdafx.h"
#include "customer.h"

Customer::Customer(){}

Customer::Customer(int idNum, string nameLast, string nameFirst) {
	id = idNum;
	last = nameLast;
	first = nameFirst;
	custHist = new History;
}

Customer::~Customer() { delete custHist; custHist = NULL; }

void Customer::printCust() {
	cout << "   ***   CUSTOMER ID: " << id << "   " <<
			first << " " << last << endl;
	custHist->printHistory();
}

bool Customer::saveCust(ofstream &outfile1, ofstream &outfile2) {
	outfile1 << id << " " << last << " " << first << endl;
	return custHist->saveHistory(id, outfile2);
}

bool Customer::getCust(stringstream &custStream) {
	custStream << last << ";" << first << ";" << id << ";";
	return true;
}