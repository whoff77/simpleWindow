// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
history.h
*****************************************************************
This is a linked list of transactions belonging to a customer.
****************************************************************/

#ifndef HISTORY
#define HISTORY

#include "movie.h"
#include "transaction.h"
class Transaction;
class BorrowMovie;
class ReturnMovie;

class History {

	friend class TransFactory;

public:
	History();
	~History();
	void append(Transaction*);
	void printHistory();
	bool saveHistory(int, ofstream &);

private:

	struct Node {
		Node(Transaction *t) {
			tPtr = t;
			next = NULL;
		}
		Transaction *tPtr;
		Node *next;                            
	};
	Node *head, *tail;

	void printTransaction(Node*);
	bool saveTransaction(Node*, int, ofstream &);
};

#endif
