/////////////////////////////////////////////////
//String length compare program
//Compare 2 strings, and determine the length to compare based on the shorter string.
//Eg.
//"Test" vs "Tester" should return equal because "Test" is shorter, so it is comparing 4 character lengths
//
//Author: Simmonson
//V 1.0.0 November 9, 2017
//
/////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char firstString[80];
	char secondString[80];
	char temp[20];
	size_t shortestLength;
	int stringAreEqual;

	cout << "Input the first string: \n\n";
	cin.getline(firstString, 80);
	cout << "\nInput the second string: \n\n";
	cin.getline(secondString, 80);

	cout << '\n' << endl;

	if (strlen(firstString) >= strlen(secondString))
	{
		shortestLength = strlen(secondString);
	}
	else
	{
		shortestLength = strlen(firstString);
	}

	stringAreEqual = strncmp(firstString, secondString, shortestLength);

	cout << "Compare strings: \n\t\t" << firstString << "\n\t\t" << secondString << '\n' << endl;

	if (stringAreEqual > 0)
	{
		strcpy(temp, " is greater than ");
	}
	else if (stringAreEqual < 0)
	{
		strcpy(temp, " is less than ");
	}
	else
	{
		strcpy(temp, " is equal to ");
	}

	cout << "Result: \t" << "String 1" << temp << "String 2\n" << endl;


	system("pause");
} //end of main