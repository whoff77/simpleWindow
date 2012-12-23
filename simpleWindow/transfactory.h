// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
transfactory.h
*****************************************************************
This class is called to determine how different transaction
types should be handled. Borrow or return will result in objects
being created and worked on, where as displaying transactions or
inventory will simply do those actions.
****************************************************************/

#ifndef TRANSFACTORY
#define TRANSFACTORY

#include "borrowmovie.h"
#include "returnmovie.h"
#include "custtable.h"

class TransFactory {
public:
	TransFactory();
	~TransFactory();
	bool create(char, ifstream &, Formats*, CustTable*,
				Transaction *&t);

private:
	int custID;
	Customer *cust;
};

#endif
