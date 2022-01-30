/******************************************************************
** Program: Chapter 11 Serendipity Booksellers Software Development: mainmenu.cpp
** Description: replace arrays w/ array of BookData structs
** Course: CS226 CRN 22343
** Professor: Ara Kechiantz
** Student: Mohammad Dembele
** Due Date: 12/07/2020
******************************************************************/
#include <cctype>

void strUpper(char* s)
{
	while (*s != 0)
	{
		*s = toupper(*s);
		s++;
	}
}
