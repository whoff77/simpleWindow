// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
customer.h
*****************************************************************
This object represents one customer, with their name and id num,
as well as a pointer to their history of transactions.
****************************************************************/

#ifndef CUSTOMER
#define CUSTOMER

#include "history.h"

class Customer {

//	friend class Transaction;
	friend class CustTable;

public:
	Customer();
	Customer(int, string, string);
	~Customer();
	void printCust();
	History *custHist;

	bool saveCust(ofstream &, ofstream &);

	bool getCust(stringstream &);

protected:
	string last, first;
	int id;
};

#endif
