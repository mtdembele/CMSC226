/******************************************************************
** Program: Chapter 11 Serendipity Booksellers Software Development: mainmenu.cpp
** Description: replace arrays w/ array of BookData structs
** Course: CS226 CRN 22343
** Professor: Ara Kechiantz
** Student: Mohammad Dembele
** Due Date: 12/07/2020
******************************************************************/
#include "invmenu.h"
#include "bookinfo.h"
#include "strupper.h"
#include "bookdata.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int numBooks = 20;
extern BookData books[numBooks];

void invMenu()
{
	int choice = 0;

	while (choice != 5)
	{
		cout << "Serendipity Booksellers\n";
		cout << "   Inventory Database\n\n";

		cout << "1. Look Up a Book\n";
		cout << "2. Add a Book\n";
		cout << "3. Edit a Book\n";
		cout << "4. Delete a Book\n";
		cout << "5. Return to the Main Menu\n\n";

		cout << "Enter Your Choice: ";
		cin >> choice;


		//input validaiton
		while (choice < 1 && choice > 4)
		{
			cout << "\nPlease enter a number in the range 1 - 5\n";
			cout << "Enter your choice: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			lookUpBook();
			break;
		case 2:
			addBook();
			break;
		case 3:
			editBook();
			break;
		case 4:
			deleteBook();
			break;

		}

		cout << endl;
	}
}

void lookUpBook()
{char title[maxStringLength],  decision = ' ';
	int i = 0;
	cin.ignore();

	cout << "Enter the title of the book to search for: ";
	cin.getline(title, maxStringLength);

	strUpper(title);

	for (i = 0; i < numBooks; i++)
	{
		if (strstr(books[i].bookTitle,title)) // checks to see if it is a substring
		{
			cout << "\nMatch found: " << books[i].bookTitle << "\n\n";
			cout << "Is this what you're looking for? (Y or N)  ";
			cin >> decision;

			while (decision != 'Y' && decision != 'y' && decision != 'N' && decision != 'n')
			{
				cout << "\nPossible Match found: " << books[i].bookTitle << "\n\n";
				cout << "(Y or N)  ";
				cin >> decision;
			}

			if (decision == 'Y' || decision == 'y')
			{
				bookInfo(books[i].isbn, books[i].bookTitle, books[i].author,
					books[i].publisher, books[i].dateAdded, books[i].qtyOnHand,
					books[i].wholesale, books[i].retail);
				break;
			}
		}
	}
	if (i > numBooks -1)
		cout << "Book not found in inventory" << endl;

}

void addBook()
{
	char title[maxStringLength], isbn[maxStringLength];
	char publisher[maxStringLength], author[maxStringLength], date[maxStringLength];
	int  quantity;
	double retail, wholesale;
	int i;

	for (i = 0; i < numBooks; i++)
	{
		if (isEmpty(i))
		{
			cin.ignore();
			cout << "Enter Title: ";
			cin.getline(title, maxStringLength);
			setTitle(title, i);

			cout << "Enter ISBN:";
			cin.getline(isbn, maxStringLength);
			setISBN(isbn, i);

			cout << "Enter Author:";
			cin.getline(author, maxStringLength);
			setAuthor(author, i);

			cout << "Enter Publisher:";
			cin.getline(publisher, maxStringLength);
			setPublisher(publisher, i);

			cout << "Enter Date Added:";
			cin.getline(date, maxStringLength);
			setDateAdded(date, i);

			cout << "Enter Quantity:";
			cin >> quantity;
			setQty(quantity, i);

			cout << "Enter Wholesale Price:";
			cin >> wholesale;
			setWholesale(wholesale, i);

			cout << "Enter Retail Price:";
			cin >> retail;
			setRetail(retail, i);

            cout << endl;
			cout << "Successfully added.";
			break;
		}
		cout << "Cannot add any more books" << endl;
	}
}

void editBook()
{
	char title[maxStringLength], isbn[maxStringLength], author[maxStringLength], pub[maxStringLength], date[maxStringLength];
	int  i, quantity, choice = 0;
	double wholesale, retail;
	char decision = ' ';

	cin.ignore();

	cout << "Enter the title of the book to edit: ";
	cin.getline(title, maxStringLength);
	strUpper(title);

	for (i = 0; i < numBooks; i++)
	{
		if (strstr(books[i].bookTitle, title))
		{
			cout << "\nPossible Match found: " << books[i].bookTitle << "\n\n";
			cout << "(Y/N)";
			cin >> decision;

			while (decision != 'Y' && decision != 'y' && decision != 'N' && decision != 'n')
			{
				cout << "Y/N\n";
				cout << "\nPossible Match found: " << books[i].bookTitle << "\n";
				cout << "(Y/N)";
				cin >> decision;
			}

			if (decision == 'Y' || decision == 'y')
			{
				bookInfo(books[i].isbn, books[i].bookTitle, books[i].author,
					books[i].publisher, books[i].dateAdded, books[i].qtyOnHand,
					books[i].wholesale, books[i].retail);

				do
				{
					cout << "\nYou may edit any of the following: " << endl;
					cout << "1. ISBN\n";
					cout << "2. Title\n";
					cout << "3. Author\n";
					cout << "4. Publisher\n";
					cout << "5. Date added\n";
					cout << "6. Quantity \n";
					cout << "7. Wholesale Pricew\n";
					cout << "8. Retail Price\n";
					cout << "9. Exit\n\n";
					cin >> choice;

					while (choice < 1 || choice > 9)
					{
						cout << "Enter your choice :";
						cin >> choice;
					}

					switch (choice)
					{
					case 1:
						cout << "\nCurrent ISBN: ";
						cout << books[i].isbn << endl;
						cin.ignore();
						cout << "New ISBN: ";
						cin.getline(isbn, maxStringLength);
						setISBN(isbn, i);
						break;
					case 2:
						cout << "\nCurrent Title: ";
						cout << books[i].bookTitle << endl;
						cin.ignore();
						cout << "New Title: ";
						cin.getline(title, maxStringLength);
						setTitle(title, i);
						break;
					case 3:
						cout << "\nCurrent Author: ";
						cout << books[i].author << endl;
						cin.ignore();
						cout << "New Author: ";
						cin.getline(author, maxStringLength);
						setAuthor(author, i);
						break;
					case 4:
						cout << "\nCurrent Publisher: ";
						cout << books[i].publisher << endl;
						cin.ignore();
						cout << "New Publisher: ";
						cin.getline(pub, maxStringLength);
						setPublisher(pub, i);
						break;
					case 5:
						cout << "\nCurrent Date Added: ";
						cout << books[i].dateAdded << endl;
						cin.ignore();
						cout << "New Date: ";
						cin.getline(date, maxStringLength);
						setDateAdded(date, i);
						break;
					case 6:
						cout << "\nCurrent Quantity on Hand: ";
						cout << books[i].qtyOnHand << endl;
						cin.ignore();
						cout << "New Quantity On Hand: ";
						cin >> quantity;
						setQty(quantity, i);
						break;
					case 7:
						cout << "\nCurrent Wholesale Price: ";
						cout << books[i].wholesale << endl;
						cin.ignore();
						cout << "New Wholesale price: ";
						cin >> wholesale;
						setWholesale(wholesale, i);
						break;
					case 8:
						cout << "\nCurrent Retail Price: ";
						cout << books[i].retail << endl;
						cin.ignore();
						cout << "New Retail Price: ";
						cin >> retail;
						setRetail(retail, i);
						break;
					}
				} while (choice != 9);
				break;
			}
		}
	} //end for loop
	if (i > numBooks - 1)
		cout << "\nNo match for : " << title << " found\n";
}


void deleteBook()
{
	char title[maxStringLength];
	int i = 0;
	char yn = ' ';

	cin.ignore();

	cout << "Enter the title of the book to delete: ";
	cin.getline(title,maxStringLength);

	strUpper(title);

	for (i = 0; i < numBooks; i ++)
	{
		if (strstr(books[i].bookTitle, title))
		{
			cout << "\nMatch found: " << books[i].bookTitle << "\n\n";
			cout << "(Y or N)";
			cin >> yn;

			while (yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n')
			{
				cout << "Please enter Y or N\n\n";
				cout << "\nPossible Match found: " << books[i].bookTitle << "\n\n";
				cout << "Is this a correct match? (Y or N)  ";
				cin >> yn;
			}
            toupper(yn);
			if (yn == 'Y' || yn == 'y')
			{
				bookInfo(books[i].isbn, books[i].bookTitle, books[i].author,
					books[i].publisher, books[i].dateAdded, books[i].qtyOnHand,
					books[i].wholesale, books[i].retail);
				cout << "Would you like to delete entire record? Y/N\: ";
				cin >> yn;

				while (yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n')
				{
					cout << "Please enter Y or N\n\n";
					cout << "\nPossible Match found: " << books[i].bookTitle << "\n\n";
					cout << "Would you like to delete entire record? Y/N\: ";
					cin >> yn;
				}

				if (yn == 'Y' || yn == 'y')
				{
					removeBook(i);
					cout << "\nSuccessfully deleted";
				}
				else
					cout << "\nNot deleted";
			}
		}
	}
	if (i > numBooks - 1)
		cout << "\nNo match for : " << title << " was found\n";
}
