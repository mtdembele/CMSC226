/******************************************************************
** Program: Chapter 11 Serendipity Booksellers Software Development: mainmenu.cpp
** Description: replace arrays w/ array of BookData structs
** Course: CS226 CRN 22343
** Professor: Ara Kechiantz
** Student: Mohammad Dembele
** Due Date: 12/07/2020
******************************************************************/
#include "reports.h"
#include "bookdata.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <cstring>


using namespace std;
const int numBooks = 20;
extern BookData books[numBooks];
char skip[] = { '\0' };

void reports()
{

	int listingChoice = 0;

	while (listingChoice != 7)
	{

		cout << "Serendipity Booksellers\n";
		cout << "\tReports\n\n";

		cout << "1. Inventory Listing\n";
		cout << "2. Inventory Wholesale Value\n";
		cout << "3. Inventory Retail Value\n";
		cout << "4. List by Quantity\n";
		cout << "5. List by Cost\n";
		cout << "6. List by Age\n";
		cout << "7. Return to the Main Menu\n\n";

		cout << "Enter Your Choice: ";
		cin >> listingChoice;

		while (listingChoice < 1 || listingChoice > 7)//input validation
		{
			cout << "Enter your choice: ";
			cin >> listingChoice;
			cout << endl;
		}
			switch (listingChoice)
			{
			case 1:
				invListing();
				break;
			case 2:
				wholesaleListing();
				break;
			case 3:
				retailListing();
				break;
			case 4:
				quantityListing();
				break;
			case 5:
				costListing();
				break;
			case 6:
				ageListing();
				break;
			case 7:
				cout << "Return";
				break;
			}

		cout << endl;

	}
}

void invListing()
{
    char date[maxStringLength]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Inventory Report\n";
	cout << "Date: \t\t" << date;

	for (int i = 0; i < numBooks; i++)
	{
		if (strcmp(books[i].isbn, skip) != 0) //skipempty
		{
			cout << "\n------------------------------------------------------";
			cout << "\n\n\Title:   \t" << books[i].bookTitle;
			cout << "\nISBN:   \t" << books[i].isbn;
			cout << "\nAuthor:   \t" << books[i].author;
			cout << "\nPublisher:   \t" << books[i].publisher;
			cout << "\nDate Added:   \t" << books[i].dateAdded;
			cout << "\nQuantity:   " << books[i].qtyOnHand;
			cout << fixed << showpoint << left << setprecision(2);
			cout << "\nWholesale Cost:   \t$ " << books[i].wholesale;
			cout << "\nRetail Price:   \t $" << books[i].retail;
		}
	}

    cout << "\n------------------------------------------------------";

	cout << "Press Enter";
	cin.ignore();
	cin.get();
}

void wholesaleListing()
{

	char date[maxStringLength]; //current date
	cout << "\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\t\tSerendipity Booksellers Wholesale Report\n";
	cout << "Date:\t\t " << date;

	cout << "\n\tTitle\t\t\t   ISBN\t\tQuantity\tWholesale\n";
	cout << "\t--------------------------------------------------\n";

	double thisSub, subTotal = 0;

	for (int i = 0; i < numBooks; i++)
	{
		if (strcmp(books[i].isbn, skip) != 0) //skip empty
		{
			cout << "\n\t" << left << setw(26) << books[i].bookTitle << left << setw(14) << books[i].isbn;
			cout << right << setw(6) << books[i].qtyOnHand << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t$" << books[i].wholesale;

			thisSub = books[i].qtyOnHand * books[i].wholesale;
			subTotal += thisSub;
		}
	}

	cout << "\n\n\n\tTotal Wholesale price: $" << subTotal << endl;
	cout << "\t-------------------------------------------------------------\n\n";

	cout << "Press Enter";
	cin.ignore();
	cin.get();
}

void retailListing()
{

	char date[maxStringLength]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Retail Listing\n";
	cout << "Date:\t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\ttQuantity\tRetail\n";

	cout << "\t---------------------------------------------------\n";

	double itemSubTotal;
	double subTotal = 0;

	for (int i = 0; i < numBooks; i++)
	{
		if (strcmp(books[i].isbn, skip) != 0) //not printing empty records
		{
			cout << "\n\t" << left << setw(26) << books[i].bookTitle;
			cout << left << setw(14) << books[i].isbn;
			cout << right << setw(6) << books[i].qtyOnHand << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t$ " << books[i].retail;

			itemSubTotal = books[i].qtyOnHand * books[i].retail;
			subTotal += itemSubTotal;
		}
	}

	cout << "\n\n\n\tTotal Retail Value: $" << subTotal << endl;
	cout << "\t--------------------------------------------------------------\n\n";
	cout << "Press Enter";
	cin.ignore();
	cin.get();
}

void quantityListing()
{
	int id[numBooks];
	int* idPtr[numBooks], *qtyPtr[numBooks];
    double* wholePtr[numBooks];
	for (int i = 0; i < numBooks; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		qtyPtr[i] = &books[i].qtyOnHand;
	}

	//selection sort
	int start,maxI;
	int* tempId;
	double* maxValue;

	for (start = 0; start < numBooks - 1; start++)
	{
		maxI = start;
		maxValue = wholePtr[start];
		tempId = idPtr[start];

		for (int index = start + 1; index < numBooks; index++)
		{
			if (*(wholePtr[index]) > *maxValue)
			{
				maxValue = wholePtr[index];
				tempId = idPtr[index];
				maxI = index;
			}
		}

		idPtr[maxI] = idPtr[start];
		wholePtr[maxI] = wholePtr[start];
		wholePtr[start] = maxValue;
		idPtr[start] = tempId;
	}

	char date[maxStringLength]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Quantity Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\n";
	cout << "\t---------------------------------------------------\n\n";

	char end[] = { '\0' };
	for (int j = 0; j < numBooks; j++)
	{
		if (strcmp(books[j].isbn, end) != 0) //not printing empty records
		{
			cout << "\n\t" << books << setw(26) << books[*(idPtr[j])].bookTitle;
			cout << left << setw(14) << books[*(idPtr[j])].isbn;
			cout << right << setw(6) << *qtyPtr[j] << "\n";
		}
	}

	cout << "\t--------------------------------------------------------------\n";


	cout << "Press Enter";
	cin.ignore();
	cin.get();
}

void costListing()
{
	int orig[numBooks];
	int* idPtr[numBooks];
	double* wholePtr[numBooks];

	for (int i = 0; i < numBooks; i++)
	{
		orig[i] = i;
		idPtr[i] = &orig[i];
		wholePtr[i] = &books[i].wholesale;
	}
    //selection sort
	int start,maxI;
	int* tempId;
	double* maxValue;

	for (start = 0; start < numBooks - 1; start++)
	{
		maxI = start;
		maxValue = wholePtr[start];
		tempId = idPtr[start];

		for (int index = start + 1; index < numBooks; index++)
		{
			if (*(wholePtr[index]) > *maxValue)
			{
				maxValue = wholePtr[index];
				tempId = idPtr[index];
				maxI = index;
			}
		}

		idPtr[maxI] = idPtr[start];
		wholePtr[maxI] = wholePtr[start];
		wholePtr[start] = maxValue;
		idPtr[start] = tempId;
	}

	char currentDate[maxStringLength]; //todays date
	cout << "\n\nEnter Today's date: ";
	cin >> currentDate;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Cost Report\n";
	cout << "Date: \t\t" << currentDate;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	cout << "\t---------------------------------------------------\n\n";

	for (int j = 0; j < numBooks; j++)
	{
		if (strcmp(books[j].isbn, skip) != 0)
		{
			cout << "\n\t" << left << setw(26) << books[*(idPtr[j])].bookTitle;
			cout << left << setw(14) << books[*(idPtr[j])].isbn;
			cout << fixed << showpoint << right << setprecision(2);
			cout << right << setw(6) << books[j].qtyOnHand;
			cout << setw(6) << "\t$ " << *wholePtr[j] << "\n";
		}
	}

	cout << "\t-------------------------------------------------------------\n";
	cout << "\n\tEnd of Cost Report\n\n\n";

	cout << "Press Enter";
	cin.ignore();
	cin.get();

}

void ageListing()
{
	int orig[numBooks]; //array to track original subscripts
	int* idPtr[numBooks]; //pointer to tracking array
	char* datePtr[numBooks]; //array of pointers to date added array

	for (int i = 0; i < numBooks; i++)
	{
		orig[i] = i;
		idPtr[i] = &orig[i];
		datePtr[i] = books[i].dateAdded;
	}

	int startScan;
	int maxIndex;
	int* tempId;
	char* maxValue;

	//selection sort
	for (startScan = 0; startScan < numBooks - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = datePtr[startScan];
		tempId = idPtr[startScan];

		for (int index = startScan + 1; index < numBooks; index++)
		{
			if (*(datePtr[index]) > *maxValue)
			{ //swap
				maxValue = datePtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		datePtr[maxIndex] = datePtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		datePtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char date[maxStringLength]; //todays date
	cout << "\n\nEnter the date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Booksellers Age Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tDateAdded\n";
	cout << "\t---------------------------------------------------\n\n";

	for (int j = 0; j < numBooks; j++)
	{
		if (strcmp(books[j].isbn, skip) != 0)
		{
			cout << "\n\t" << left << setw(26) << books[*(idPtr[j])].bookTitle;
			cout << left << setw(14) << books[*(idPtr[j])].isbn;
			cout << right << setw(6) << books[j].qtyOnHand;
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t " << books[*(idPtr[j])].dateAdded << "\n";
		}
	}

	cout << "\t--------------------------------------------------------------\n";
	cout << "\n\tEnd of Age Report\n\n\n";

	cout << "Press Enter";
	cin.ignore();
	cin.get();
}
