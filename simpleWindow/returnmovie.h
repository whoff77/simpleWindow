// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
returnmovie.h
*****************************************************************
Derived from Transaction class, available movies is incremented.
****************************************************************/

#ifndef RETURNMOVIE
#define RETURNMOVIE

#include "transaction.h"

class ReturnMovie : public Transaction {

public:
	ReturnMovie();
	ReturnMovie(ifstream &, Formats*);
	~ReturnMovie();
	virtual void executeCommand();
};

#endif
