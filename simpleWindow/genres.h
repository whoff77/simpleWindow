// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
genres.h
*****************************************************************
This is a linked list of available genres, each of which link
to a set<Movie> of objects that have been cast to the
corresponding genre.
****************************************************************/

#ifndef GENRES
#define GENRES

#include "movie.h"
#include <set>

class Genres
{
public:
	Genres();
	~Genres();

	void append(char, Movie*);
	bool getMovie(char, Movie*&);
	void printMovies();

	bool saveGenres(char, ofstream &);

private:
	struct Compare {
		bool operator() (const Movie* lhs, const Movie* rhs) const
		{ return *lhs < *rhs; }
	};
	struct Node {
		Node(char genre, Movie* m) {
			theGenre = genre;
			next = NULL;
			setPtr = new set<Movie*, Compare>;
			setPtr->insert(m);
		}
		char theGenre;
		set<Movie*, Compare> *setPtr;
		Node *next;                                   
	};
	Node *head, *tail;
	set<Movie*, Compare> *s;
	set<Movie*, Compare>::iterator it;
	
	void deleteMovies(Node*);
	bool findGenre(Node*, char, set<Movie*, Compare>*&);
	bool getMovieHelper(Node*, char, Movie*&);
};

#endif
