// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
moviestore.cpp
*****************************************************************
MovieStore is the manager class, which handles input files, sends
them off to the movie/transaction factories and adds objects to
their respective data structures.
****************************************************************/

#include "stdafx.h"
#include "moviestore.h"

MovieStore::MovieStore() {
	mFormats = new Formats;
	custList = new CustTable;
}

MovieStore::~MovieStore() {
	delete mFormats;
	mFormats = NULL;
	delete custList;
	custList = NULL;
}

bool MovieStore::uploadMovies(string movies) {
	ifstream infile(movies.c_str());
	if (!infile) {
		cout << "Movies file could not be opened." << endl;
		return false;
	}
	for(;;) {
		infile >> mFormat >> mGenre;
		if (infile.eof()) break;
		if (mFactory.create(mFormat, mGenre, m)) {
			m->populate(infile);
			mFormats->append(mFormat, mGenre, m);
		} else getline(infile, junk);
		m = NULL;
	}
	infile.close();
	return true;
}


bool MovieStore::uploadCustomers(string customers) {
	ifstream infile(customers.c_str());
	if (!infile) {
		cout << "Customers file could not be opened." << endl;
		return false;
	}
	for (;;) {
		infile >> custID >> nameLast >> nameFirst;
		if (infile.eof()) break;
		cust = new Customer(custID, nameLast, nameFirst);
		custList->addCust(cust);
		cust = NULL;
	}
	infile.close();
	return true;
}


bool MovieStore::uploadCommands(string commands) {
	ifstream infile(commands.c_str());
	if (!infile) {
		cout << "Commands file could not be opened." << endl;
		return false;
	}

	for(;;) {
		infile >> tType;
		if (infile.eof()) break;
		if (!tFactory.create(tType, infile, mFormats, custList, t))
			getline(infile, junk);
	}
	infile.close();
	return true;
}

bool MovieStore::addCustomer(string nameLast, string nameFirst) {
	if (!custList->getNewID(custID)) return false;
	cust = new Customer(custID, nameLast, nameFirst);
	bool success = custList->addCust(cust);
	cust = NULL;
	return success;
}


bool MovieStore::saveMovies(string movieFile) {
	bool success;
	ofstream outfile(movieFile.c_str(), ios::out | ios::trunc);
	if (!outfile) {
		cout << "Movies file could not be opened." << endl;
		return false;
	}
	//outfile << "testing 123" << endl;
	//outfile << "testing 456" << endl;
	success = mFormats->saveFormats(outfile);
	outfile.close();
	return success;
}

bool MovieStore::saveAccounts(string custFile, string transFile) {
	bool success;

	ofstream outfile1(custFile.c_str(), ios::out | ios::trunc);
	if (!outfile1) {
		cout << "Customers file could not be opened." << endl;
		return false;
	}

	ofstream outfile2(transFile.c_str(), ios::out | ios::app);
	if (!outfile2) {
		cout << "Transactions file could not be opened." << endl;
		return false;
	}

	//outfile << "testing 456" << endl;
	success = custList->saveCusts(outfile1, outfile2);
	outfile1.close();
	outfile2.close();
	return success;
}

void MovieStore::printTrans() {
	custList->printCusts();
}

bool MovieStore::getCustList(stringstream &custStream) {

	//TCHAR custArray[] = _T("lastTest1;firstTest1;idnumTest1;lastTest2;firstTest2;idnumTest2");
	//custStringPtr = new TCHAR[sizeof(custArray)];
	//_tcscpy(custStringPtr, custArray);
	return custList->getCusts(custStream);
}