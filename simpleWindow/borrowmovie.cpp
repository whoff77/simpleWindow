// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
borrowmovie.cpp
*****************************************************************
Derived from Transaction class, available movies is decremented.
****************************************************************/

#include "stdafx.h"
#include "borrowmovie.h"

BorrowMovie::BorrowMovie() : Transaction() {}

BorrowMovie::BorrowMovie(ifstream &infile, Formats *fList) : Transaction(infile, fList) {
	type = 'B';
}

BorrowMovie::~BorrowMovie(){}

void BorrowMovie::executeCommand() {
	mov->decrement();
}
