// William Hoffrance    3/10/2012    CSS 502        Assignment 3
/****************************************************************
lab3.cpp
*****************************************************************
This program allows customers to borrow and return items, and to
display the contents of the business and its customers' history of
rentals at any time. All movies are displayed by category, sorted
within the category. Output must be formatted for easy reading
with data in columns. Sample output will be given on the website.
The program initializes the contents of each of the three
categories of videos, and processes an arbitrary sequence of
borrows, returns, and displays of different kinds of information.
****************************************************************/

#include "moviestore.h"

int main() {

   // Create a movie store
   MovieStore aStore;

   // Upload all the movies
   if (aStore.uploadMovies("data3movies.txt"))
	   cout << "movies file uploaded" << endl;
   else cout << "failed to upload movies file" << endl;

   // Upload all the customers
   if (aStore.uploadCustomers("data3customers.txt")) // try custAccounts2.txt
	   cout << "customers file uploaded" << endl;
   else cout << "failed to upload customers file" << endl;

   // Upload all the commands
   if (aStore.uploadCommands("data3commands.txt"))
	   cout << "commands file uploaded" << endl;
   else cout << "failed to upload commands file" << endl;


   // Add a customer
   if (aStore.addCustomer("Wayne", "Bruce"))
	   cout << "customer \"Bruce Wayne\" added" << endl;
   else cout << "failed to add customer \"Bruce Wayne\"" << endl;


   // Save all movies to file
   if (aStore.saveMovies())
	   cout << "movie file updated" << endl;
   else cout << "failed to update movie file" << endl;

   // Save all customers & transactions to file w/ default filename
   if (aStore.saveAccounts())
	   cout << "default accounts file updated" << endl;
   else cout << "failed to update default account file" << endl;

   // Save all customers & transactions to file w/ custom filename
   if (aStore.saveAccounts("custAccounts2.txt", "transHistory2.txt"))
	   cout << "custom accounts file updated" << endl;
   else cout << "failed to update custom account file" << endl;

   
   //aStore.printTrans(); // Print all transactions

   system ("pause");

   return 0;
}
