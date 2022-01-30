/******************************************************************
** Program: Chapter 11 Serendipity Booksellers Software Development: bookinfo.cpp
** Description: Displays book info
** Course: CS226 CRN 22343
** Professor: Ara Kechiantz
** Student: Mohammad Dembele
** Due Date: 11/01/2020
******************************************************************/
#include "bookinfo.h"
#include <iostream>

using namespace std;
const int strSize = 51;

void bookInfo(char isbn[strSize], char title[strSize], char author[strSize], char publisher[strSize], char date[strSize], int qty, double wholesale, double retail)
{
	cout << "Serendipity Booksellers\n";
	cout << "\tBook Information\n\n";

	cout << "ISBN: " << isbn << "\nTitle: " << title << "\nAuthor: " << author << "\n";
	cout << "Publisher: " << publisher << "\nDate Added: " << date << "\n";
	cout << "Quantity on Hand: " << qty << "\nWholesale Cost: " << wholesale << "\n";
	cout << "Retail Price: " << retail << "\n";

	cout << "Enter Your Choice: "; //option to return to menu or continue
}
