// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
transaction.h
*****************************************************************
Base class for transactions that can be added to a customer's
history. All the customer/movie data is handled in this class.
****************************************************************/

#ifndef TRANSACTION
#define TRANSACTION

#include "formats.h"
#include "moviefactory.h"

class Transaction {

	friend ostream& operator<<(ostream&, const Transaction &);

public:
	Transaction();
	Transaction(ifstream &, Formats*);
	virtual ~Transaction();
	virtual void executeCommand();
	bool valid;

	string stringTransaction();

protected:
	char type, format, genre;
	Movie *mov;
	MovieFactory movFactory;
	string tempJunkDelete;

private:
	virtual bool generateCommand(ifstream &, Formats*);
};

#endif
