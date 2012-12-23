// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
returnmovie.cpp
*****************************************************************
Derived from Transaction class, available movies is incremented.
****************************************************************/

#include "stdafx.h"
#include "returnmovie.h"

ReturnMovie::ReturnMovie() : Transaction() {}

ReturnMovie::ReturnMovie(ifstream &infile, Formats *fList) : Transaction(infile, fList) {
	type = 'R';
}

ReturnMovie::~ReturnMovie(){}

void ReturnMovie::executeCommand() {
	mov->increment();
}
