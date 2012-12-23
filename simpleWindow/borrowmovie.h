// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
borrowmovie.h
*****************************************************************
Derived from Transaction class, available movies is decremented.
****************************************************************/

#ifndef BORROWMOVIE
#define BORROWMOVIE

#include "transaction.h"

class BorrowMovie : public Transaction {

public:
	BorrowMovie();
	BorrowMovie(ifstream &, Formats*);
	~BorrowMovie();
	virtual void executeCommand();
};

#endif
