// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
history.cpp
*****************************************************************
This is a linked list of transactions belonging to a customer.
****************************************************************/

#include "stdafx.h"
#include "history.h"

History::History() { head = tail = NULL; }

History::~History() {
	while (head != NULL) {
		Node* save = head;
		head = head->next;
		delete save->tPtr;
		save->tPtr = NULL;
		delete save;  save = NULL;
	}
	tail = NULL;
}

void History::append(Transaction *t) {
	if (head == NULL) head = tail = new Node(t);
	else {
		tail->next = new Node(t);
		tail = tail->next;
	}
}

void History::printHistory() {
	printTransaction(head);
}
void History::printTransaction(Node *cur) {
	if (cur == NULL) return;
	cout << *cur->tPtr;
	printTransaction(cur->next);
}

bool History::saveHistory(int id, ofstream &outfile) {
	return saveTransaction(head, id, outfile);
}
bool History::saveTransaction(Node *cur, int id, ofstream &outfile) {
	if (cur == NULL) return true;
	outfile << id << " " << cur->tPtr->stringTransaction() << endl;
	return saveTransaction(cur->next, id, outfile);
}