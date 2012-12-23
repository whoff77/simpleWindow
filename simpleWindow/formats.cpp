// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
formats.cpp
*****************************************************************
This is a linked list of available formats, each of which link
to a 'Genres' object (which is another linked list of available
genres).
****************************************************************/

#include "stdafx.h"
#include "formats.h"

Formats::Formats() { head = tail = NULL; }


Formats::~Formats() {
	while (head != NULL) {
		Node* save = head;
		head = head->next;
		delete save->genresPtr;
		save->genresPtr = NULL;
		delete save;  save = NULL;
	}
	tail = NULL;
}
        
void Formats::append(char format, char genre, Movie *m) {
	if (head == NULL) head = tail = new Node(format, genre, m);
	else if (findFormat(head, format, g)) g->append(genre, m);
	else {
		tail->next = new Node(format, genre, m);
		tail = tail->next;
	}
}

// recursive search for existing format
bool Formats::findFormat(Node* cur, char format, Genres *&g) {
	if (cur == NULL) return false;
	if (cur->theFormat == format) {
		g = cur->genresPtr;
		return true;
	}
	return findFormat(cur->next, format, g);
}

bool Formats::getMovie(char format, char genre, Movie *&mov) {
	return getMovieHelper(head, format, genre, mov);
}
bool Formats::getMovieHelper(Node* cur, char format, char genre,
							 Movie *&mov) {
	if (cur == NULL) return false;
	if (cur->theFormat == format)
		return cur->genresPtr->getMovie(genre, mov);
	return getMovieHelper(cur->next, format, genre, mov);
}


void Formats::printMovies() {
	for (Node* p = head; p != NULL; p = p->next) {
		cout << "FORMAT: " << p->theFormat << endl;
		p->genresPtr->printMovies();
	}
}

bool Formats::saveFormats(ofstream &outfile) {
	for (Node* s = head; s != NULL; s = s->next) {
		if (!s->genresPtr->saveGenres(s->theFormat, outfile))
			return false;
	}
	return true;
}