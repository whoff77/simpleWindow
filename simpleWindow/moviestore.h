// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
moviestore.h
*****************************************************************
MovieStore is the manager class, which handles input files, sends
them off to the movie/transaction factories and adds objects to
their respective data structures.
****************************************************************/

#ifndef MOVIESTORE
#define MOVIESTORE

#include "transfactory.h"
#include <vector>

class MovieStore {

protected:

public:
	MovieStore();
	~MovieStore();

	bool uploadMovies(string);
	// void printMovies();
	bool uploadCustomers(string);
	// void printCustomers();
	bool uploadCommands(string);

	// add one customer to file
	bool addCustomer(string, string);

	// save movies to file
	bool saveMovies(string = "movieInventory.txt");

	// save customers and append all new transactions to file
	bool saveAccounts(string = "custAccount.txt", string = "transHistory.txt");
	void printTrans();

	bool getCustList(stringstream &);

private:
	
	int custID;
	char mFormat, mGenre, tType;
	string nameLast, nameFirst, junk;
	TCHAR nameLastT, nameFirstT, junkT;
	MovieFactory mFactory;
	TransFactory tFactory;
	Movie *m;
	Formats *mFormats;
	Customer *cust;
	CustTable *custList;
	Transaction *t;
};

#endif
