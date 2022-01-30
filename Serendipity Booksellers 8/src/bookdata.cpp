/******************************************************************
** Program: Chapter 11 Serendipity Booksellers Software Development: mainmenu.cpp
** Description: replace arrays w/ array of BookData structs
** Course: CS226 CRN 22343
** Professor: Ara Kechiantz
** Student: Mohammad Dembele
** Due Date: 12/07/2020
******************************************************************/
#include <cstring>
#include "bookdata.h"
#include "strupper.h"

using namespace std;

const int numBooks = 20;
extern BookData books[numBooks];

int isEmpty(int sub) //sub = subscript
{
	if (books[sub].bookTitle[0] == 0)
		return 1;
	else
		return 0;
}

void removeBook(int sub)
{
	books[sub].bookTitle[0] = 0;
	books[sub].isbn[0] = 0;
}
void setTitle(char* newTitle, int sub)
{
	strUpper(newTitle);
	strcpy(books[sub].bookTitle, newTitle);
}

void setISBN(char* newISBN, int sub)
{
	strUpper(newISBN);
	strcpy(books[sub].isbn, newISBN);
}

void setAuthor(char* newAuthor, int sub)
{
	strUpper(newAuthor);
	strcpy(books[sub].author, newAuthor);
}

void setPublisher(char* newPublisher, int sub)
{
	strUpper(newPublisher);
	strcpy(books[sub].publisher, newPublisher);
}

void setDateAdded(char* newDate, int sub)
{
	strUpper(newDate);
	strcpy(books[sub].dateAdded, newDate);
}

void setQty(int newQuantity, int sub)
{
	books[sub].qtyOnHand = newQuantity;
}

void setWholesale(double newWholesale, int sub)
{
	books[sub].wholesale = newWholesale;
}

void setRetail(double newRetail, int sub)
{
	books[sub].retail = newRetail;
}

