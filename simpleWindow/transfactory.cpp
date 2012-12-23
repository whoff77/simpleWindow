// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
transfactory.cpp
*****************************************************************
This class is called to determine how different transaction
types should be handled. Borrow or return will result in objects
being created and worked on, where as displaying transactions or
inventory will simply do those actions.
****************************************************************/

#include "stdafx.h"
#include "transfactory.h"

TransFactory::TransFactory(){}

TransFactory::~TransFactory(){}

bool TransFactory::create(char type, ifstream &infile, Formats
						  *formatList, CustTable *custList,
						  Transaction *&t) {
	switch(type) {
	case 'B':
		infile >> custID;
		if (!custList->getCust(custID, cust)) return false;
		t = new BorrowMovie(infile, formatList);
		if (t->valid) {
			t->executeCommand();
			cust->custHist->append(t);
			return true;
		} else {
			delete t;
			return false;
		}
	case 'R':
		infile >> custID;
		if (!custList->getCust(custID, cust)) return false;
		t = new ReturnMovie(infile, formatList);
		if (t->valid) {
			t->executeCommand();
			cust->custHist->append(t);
			return true;
		} else {
			delete t;
			return false;
		}
	case 'H':
		cout << endl << endl;
		infile >> custID;
		if (!custList->findCust(custID)) return false;
		//custList->getCust(custID, cust);
		//cust->custHist->printHistory();
		//cout << cust->custHist->head->tPtr->custID;
		return custList->printCust(custID);

	case 'S':
		cout << endl << endl;
		formatList->printMovies();
		return true;

	default:
		cout << "ERROR: '" << type;
		cout << "' is an invalid transaction type." << endl;
		return false;
	}
}
