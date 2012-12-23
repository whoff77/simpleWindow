// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
custtable.h
*****************************************************************
This is a hash table to store customers, using their id number
as the insert/retrieve key.
****************************************************************/

#include "stdafx.h"
#include "custtable.h"

CustTable::CustTable() {
	srand (time(NULL));
	custArray = new Customer *[MAXARRAY];
	for (int i = 0; i < MAXARRAY; i++) custArray[i] = NULL;
}

CustTable::~CustTable() {
	for (int i = 0; i < MAXARRAY; i++)
		if (custArray[i] != NULL) delete custArray[i];
	delete[] custArray;
	custArray = NULL;
}

bool CustTable::addCust(Customer *cust) {
	for (int i = 0; i < MAXARRAY; i++) {
		if (custArray[(cust->id + i^2) % MAXARRAY] == NULL) {
			custArray[(cust->id + i^2) % MAXARRAY] = cust;
			return true;
		}
	}
	cout << "ERROR: unable to add customer \"" << cust->id << "\"" << endl;
	return false;
}

bool CustTable::getCust(int idNum, Customer *&cust) {
	for (int i = 0; i < MAXARRAY; i++) {
		if (custArray[(idNum + i^2) % MAXARRAY] == NULL) return false;
		if (custArray[(idNum + i^2) % MAXARRAY]->id == idNum) {
			cust = custArray[(idNum + i^2) % MAXARRAY];
			return true;
		}
	}
	cout << "ERROR: unable to get customer \"" << idNum << "\"" << endl;
	return false;

}

bool CustTable::findCust(int idNum) {
	for (int i = 0; i < MAXARRAY; i++) {
		if (custArray[(idNum + i^2) % MAXARRAY] == NULL) return false;
		if (custArray[(idNum + i^2) % MAXARRAY]->id == idNum) return true;
	}
	cout << "ERROR: unable to find customer \"" << idNum << "\"" << endl;
	return false;
}

bool CustTable::printCust(int idNum) {
	for (int i = 0; i < MAXARRAY; i++) {
		if (custArray[(idNum + i^2) % MAXARRAY] == NULL) return false;
		if (custArray[(idNum + i^2) % MAXARRAY]->id == idNum) {
			curCust = custArray[(idNum + i^2) % MAXARRAY];
			curCust->printCust();
			return true;
		}
	}
	cout << "ERROR: unable to print customer \"" << idNum << "\"" << endl;
	return false;
}

void CustTable::printCusts() {
	for (int i = 0; i < MAXARRAY; i++) {
		if (custArray[i] != NULL) {
			custArray[i]->printCust();
			cout << "location [" << i << "]" << endl << endl;
		}
	}
}

bool CustTable::saveCusts(ofstream &outfile1, ofstream &outfile2) {
	for (int i = 0; i < MAXARRAY; i++) {
		if (custArray[i] != NULL)
			if (!custArray[i]->saveCust(outfile1, outfile2)) return false;
	}
	return true;
}

bool CustTable::getNewID(int &idNum) {
	idNum = rand() % MAXIDNUM + 1000;
	for (int i = 1000; i < MAXIDNUM + 1; i++) {
		if (!findCust(idNum)) {
			return true;
			cout << "assigning customer ID number: " << idNum << endl;
		}
		idNum = (idNum < MAXIDNUM ? idNum + 1 : 1000);
	}
	cout << "ERROR: unable to assign customer ID number" << endl;
	return false;
}

bool CustTable::getCusts(stringstream &custStream) {
	for (int i = 0; i < MAXARRAY; i++)
		if (custArray[i] != NULL) custArray[i]->getCust(custStream);
	//char charArray[] = "lastTest1;firstTest1;idnumTest1;lastTest2;firstTest2;idnumTest2";
	return true;
}
