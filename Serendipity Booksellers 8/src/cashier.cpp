/******************************************************************
** Program: Chapter 11 Serendipity Booksellers Software Development: cashier.cpp
** Description: Modify to work with the struct array
** Course: CS226 CRN 22343
** Professor: Ara Kechiantz
** Student: Mohammad Dembele
** Due Date: 11/01/2020
******************************************************************/
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include "strupper.h";
#include "bookdata.h"
#include "cashier.h"

using namespace std;

const int numBooks = 20;
extern BookData books[numBooks];

void cashier()
{

    const double salesTax = 0.06; //6% sales tax
    char isbnNumber[numBooks][maxStringLength]; // stores isbns
    char thisTitle[numBooks][maxStringLength]; //stores titles
    int quantityOfBooks[numBooks]; //stores num of books
    double unitPrice[numBooks], subTotal[numBooks];//stores price of books
    char transDate[maxStringLength]; //stores the date of the transaction
    double currentSalesTax,runningTotal,total;
    currentSalesTax = runningTotal = total  = 0;
    char choice = 'Y';
    int currentLine = 0; //keeps track of what line we are on

    //process another transaction
    while (choice == 'Y' || choice == 'y')
    {
        //header
        cout << "Serendipity Booksellers\n";
        cout << "  Cashier Module\n\n";
        // print date
        cout << "Enter Date: ";
        cin.getline(transDate,maxStringLength);
        //print ISBN
        cout << "Enter ISBN: ";
        cin.getline(isbnNumber[currentLine],maxStringLength);
        strUpper(isbnNumber[currentLine]);
        //print price etc.
        for (int i = 0; i < numBooks; i++)
        {
            if (strcmp(isbnNumber[currentLine],books[i].isbn) == 0) // compares isbn to isbns in database
            {
                cout << "Title: " << books[i].bookTitle << endl;
                cout << fixed << showpoint << setprecision(2) << "Price: " << books[i].retail << endl; //print price

                unitPrice[currentLine] = books[i].retail;
                strcpy(thisTitle[currentLine], books[i].bookTitle);


                if (books[i].qtyOnHand == 0) //no more in stock
                {
                    cout << "Out of stock!\n";
                    return;
                }

                cout << "Enter Quantity of Book to buy: ";
                cin >> quantityOfBooks[currentLine];

                while (quantityOfBooks[currentLine] < 1 || quantityOfBooks[currentLine] > books[i].qtyOnHand)
                {
                    if (quantityOfBooks[currentLine] < 1)
                        cout << "\nEnter a higher quantity.\n\n";
                    else
                        cout << "\nInsufficient amount in inventory\n\n";

                    cout << "Enter Quantity: ";
                    cin >> quantityOfBooks[currentLine];
                }

                books[i].qtyOnHand -= quantityOfBooks[currentLine];
                currentLine++;
                choice = nextTransaction("\nAdd another book to this order?");
                cout << endl;
                break;
            }
            else if (i == numBooks - 1)
            {
                cout << "\nISBN not found.\n";

                choice = nextTransaction("Enter another ISBN?\n");
            }
        }

        cout << endl;
    }

    if (currentLine > 0)
    {
        cout << "Date: " << transDate << "\n\n";

        cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal";
        cout << "\n-------------------------------------------------------------------------------------\n\n\n";

        for (int i = 0; i < currentLine; i++)
        {
            subTotal[i] = (quantityOfBooks[i] * unitPrice[i]);
            currentSalesTax += (subTotal[i] * salesTax);
            runningTotal += subTotal[i];
            total = currentSalesTax + runningTotal;

            //display book information
            cout << quantityOfBooks[i] << "\t";
            cout << left << setw(15) << isbnNumber[i] << "\t" << left << setw(27) << thisTitle[i] << "\t$ ";
            cout << fixed << showpoint << right << setprecision(2) << setw(6) << unitPrice[i] << "\t$ " << setw(6) << subTotal[i] << "\n\n\n"; //set up and print decimals
        }

        // totals
        cout << "\t\tSubtotal\t\t\t\t\t\t$ ";
        cout << setw(7) << runningTotal << "\n";
        cout << "\t\tTax\t\t\t\t\t\t\t$ ";
        cout << setw(7) << currentSalesTax << "\n";
        cout << "\t\tTotal\t\t\t\t\t\t\t$ ";
        cout << setw(7) << total << "\n\n";

        cout << "\n\nThank you for shopping with us!\n\n";
    }

    cout << endl;
}

char nextTransaction(string s)
{
    char answer;
    cout << s;
    cout << "Enter Y for Yes, N for No\n";
    cin >> answer;
    cin.ignore();
    toupper(answer);
    while (answer != 'Y' &&  answer != 'N' )
    {
        cout << "\nEnter Y or N \n\n";
        cout << s << endl;
        cin >> answer;
        cin.ignore();
    }

    return answer;
}
