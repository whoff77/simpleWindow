// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
formats.h
*****************************************************************
This is a linked list of available formats, each of which link
to a 'Genres' object (which is another linked list of available
genres).
****************************************************************/

#ifndef FORMATS
#define FORMATS

#include "genres.h"

class Formats
{
public:
	Formats();
	~Formats();

	void append(char, char, Movie*);
	bool getMovie(char, char, Movie*&);
	void printMovies();

	bool saveFormats(ofstream &);

private:
	struct Node {
		Node(char format, char genre, Movie* m) {
			theFormat = format;
			genresPtr = new Genres;
			genresPtr->append(genre, m);
			next = NULL;
		}
		char theFormat;
		Genres *genresPtr; // pointer to the data
		Node *next;                                   
	};
	Node *head, *tail;
	Genres *g; // temp pointer used in findFormat & append
		
	bool findFormat(Node*, char, Genres*&);
	bool getMovieHelper(Node*, char, char, Movie*&);
};

#endif
