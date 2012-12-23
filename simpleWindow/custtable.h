// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
custtable.h
*****************************************************************
This is a hash table to store customers, using their id number
as the insert/retrieve key.
****************************************************************/

#ifndef CUSTTABLE
#define CUSTTABLE

#include "customer.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iterator>


class CustTable {
public:
	CustTable();
	~CustTable();
	bool addCust(Customer*);
	bool getCust(int, Customer*&);
	bool findCust(int);
	bool printCust(int);
	void printCusts();
	bool saveCusts(ofstream &, ofstream &);
	bool getNewID(int &);
	bool getCusts(stringstream &);

protected:
	Customer **custArray;
	Customer *curCust;

private:
	int const static MAXARRAY = 29;
	int const static MAXIDNUM = 8999; //1k less than actual max
};

#endif
