/******************************************************************
** Program: Chapter 11 Serendipity Booksellers Software Development: mainmenu.cpp
** Description: replace arrays w/ array of BookData structs
** Course: CS226 CRN 22343
** Professor: Ara Kechiantz
** Student: Mohammad Dembele
** Due Date: 12/07/2020
******************************************************************/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "bookinfo.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include "bookdata.h"

using namespace std;

const int numBooks = 20;
BookData books[numBooks]; // array of structs
const char fileName[] = "inventory.dat";
fstream invFile;

int main()
{
    invFile.open(fileName,ios::in);

    if (invFile.fail()){
        invFile.open(fileName,ios::in);
        invFile.close();
        invFile.clear();
        cout << "File created. Press enter to continue.\n";
        addBook();
    } else {
    int i=0;

    while (!invFile.eof() && i<numBooks){
        invFile.seekg(i*sizeof(books), ios::beg);
        invFile.read(reinterpret_cast<char*>(&books),sizeof(books));
        books[i];
        i++;
    }
    invFile.close();
    invFile.clear();
    }
	int moduleChoice = 0;

	while (moduleChoice != 4)
	{
		cout << "Serendipity Booksellers\n";
		cout << "\tMain Menu\n\n";
		cout << "1. Cashier Module\n";
		cout << "2. Inventory Database Module\n";
		cout << "3. Report Module\n";
		cout << "4. Exit\n\n";
		cout << "Enter your Choice: ";
		cin >> moduleChoice;

		//validate input
		while (moduleChoice < 1 || moduleChoice > 4)
		{
			cout << "Enter your choice: ";
			cin >> moduleChoice;
		}
			switch (moduleChoice)
			{
			case 1:
				cashier();
				break;
			case 2:
				invMenu();
				break;
			case 3:
				reports();
				break;
			case 4:
			    invFile.open(fileName,ios::out);
			    for (int j=0;j<numBooks;j++)
                {
                    invFile.seekp(j*sizeof(books), ios::beg);
                    invFile.write(reinterpret_cast<char*>(&books),sizeof(books));

                }
                invFile.close();
                invFile.clear();
				cout << "\nExit";
				break;
			}
		cout << "\n\n\n";
	}
	return 0;
}
