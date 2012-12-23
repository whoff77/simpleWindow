// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
genres.cpp
*****************************************************************
This is a linked list of available genres, each of which link
to a set<Movie> of objects that have been cast to the
corresponding genre.
****************************************************************/

#include "stdafx.h"
#include "genres.h"

Genres::Genres() { head = tail = NULL;}

Genres::~Genres() {
	while (head != NULL) {
		Node* save = head;
		head = head->next;
		deleteMovies(save);
		delete save->setPtr;
		save->setPtr = NULL;
		delete save;  save = NULL;
	}
	tail = NULL;
}

void Genres::deleteMovies(Node* cur) {
	
	for(it = cur->setPtr->begin(); it != cur->setPtr->end(); it++)
		delete *it;
}
        
void Genres::append(char genre, Movie *m) {
	if (head == NULL) head = tail = new Node(genre, m);
	else if (findGenre(head, genre, s)) s->insert(m);
	else {
		tail->next = new Node(genre, m);
		tail = tail->next;
	}
}

// recursive search for existing format
bool Genres::findGenre(Node* cur, char genre,
					   set<Movie*, Compare> *&s) {
	if (cur == NULL) return false;
	if (cur->theGenre == genre) {
		s = cur->setPtr;
		return true;
	}
	return findGenre(cur->next, genre, s);
}


bool Genres::getMovie(char genre, Movie *&mov) {
	return getMovieHelper(head, genre, mov);
}
bool Genres::getMovieHelper(Node* cur, char genre, Movie *&mov) {
	if (cur == NULL) return false;
	if (cur->theGenre == genre) {
		it = cur->setPtr->find(mov);
		if (it == cur->setPtr->end()) {
			cout << "ERROR: movie not found." << endl;
			return false;
		}
		delete mov;
		mov = *it;
		return true;
	}
	return getMovieHelper(cur->next, genre, mov);
}


void Genres::printMovies() {
	for (Node* p = head; p != NULL; p = p->next) {
		cout << "GENRE: " << p->theGenre << endl;
		cout << "IN OUT " << left << setw(22) << "TITLE" << left <<
				setw(17) << "DIRECTOR" << "YEAR MO  " << "ACTOR" << endl;
		for(it = p->setPtr->begin(); it != p->setPtr->end(); it++)
			cout << **it;
			//it._Ptr->_Myval->printMovie();
		cout << endl;
	}
}

bool Genres::saveGenres(char theFormat, ofstream &outfile) {
	for (Node* p = head; p != NULL; p = p->next) {
		for(it = p->setPtr->begin(); it != p->setPtr->end(); it++)
			//if (!it._Mynode()->_Myval->saveMovie(theFormat, p->theGenre, outfile))
			//if (!it._Ptr->_Myval->saveMovie(theFormat, p->theGenre, outfile))
			if (!(*it)->saveMovie(theFormat, p->theGenre, outfile))
				return false;
	}
	return true;
}