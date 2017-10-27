#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


bool isUnique(unsigned int, int [], const size_t);//function prototype to determine if number is unique
void pushToArray(unsigned int, int[]);
bool isInRange(int);
void printAllNumbers(const int[]);

int main() 
{
	//array to hold input
	const size_t size = 20;
	unsigned int counter = 1;
	int numbers[size];
	int userInput;

	//prompt user to enter a number
	while (counter <= 20)
	{	
		//Prompt user
		cout << "\nEnter # " << counter << " : ";
		//read input
		cin >> userInput;

		//if user input is out of the 1 - 100 range, print error
		if (isInRange(userInput))
		{	
			//check if array already has the user input
			if (isUnique(userInput, numbers, 20))
			{
				cout << "The number: " << userInput << " is unique" << endl;
			}
			//if within range, put into array
			pushToArray(userInput, numbers);
			counter++;
		}
		else {
			cout << "The number entered is not in the valid range of 10 to 100" << endl;
		}
	}

	//once all 20 numbers is in, print only the unique numbers


	system("pause");
	
}//end of main

void printAllNumbers(const int arrayOfNumbers[])
{	

}

bool isUnique(unsigned int numberToCheck, int arrayOfNumbers[], const size_t sizeOfArray)
{
	for (size_t i = 0; i < sizeOfArray; i++)
	{
		if (numberToCheck == arrayOfNumbers[i])
		{
			return false;
		}
	}
	return true;
}

bool isInRange(int input)
{
	if (input >= 10 && input <= 100)
	{
		return true;
	}
	return false;
}

void pushToArray(unsigned int input, int arrayUsed[])
{
	static size_t arrayIndex = 0;

	arrayUsed[arrayIndex] = input;

	arrayIndex++;
}