#include <iostream>
#include <array>
#include <iomanip>

using namespace std;


const size_t size = 20;
const size_t unique = 2;

bool isUnique(unsigned int, const array<int, ::size> &, const size_t);//function prototype to determine if number is unique
void pushToArray(unsigned int, array<int, ::size> &);
bool isInRange(int);
void printAllNumbers(const array<int, ::size> &);

int main()
{
	array< int, ::size> numbers;//array to hold unique numbers from user
	unsigned int counter = 1;//counter
	int userInput;//userInput automatic variable
	const unsigned int nonUnique = 0;//automatic variable to pass in if user input is not unique


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

				//user input is unique number, so push that number to array
				pushToArray(userInput, numbers);
			}
			else
			{
				pushToArray(nonUnique, numbers);//push 0 to array, and do not print anything
			}
			counter++;
		}
		else
		{
			cout << "The number entered is not in the valid range of 10 to 100" << endl;

		}
	}

	//once all 20 numbers is in, print only the unique numbers
	printAllNumbers(numbers);


	system("pause");

}//end of main



void printAllNumbers(const array<int, ::size> & arrayUsed)
{
	cout << "\nThe unique numbers are: \n" << endl;

	unsigned int characterCount = 0;

	for (auto index : arrayUsed)
	{
		if (index > 0 && characterCount < 30)
		{
			cout << setw(6) << index;
			characterCount += 6;
		}
		else if (index > 0)
		{
			cout << '\n' << setw(6) << index;
			characterCount = 6;
		}
	}

	cout << '\n' << endl;
}

bool isUnique(unsigned int numberToCheck, const array<int, ::size> & arrayToCheck, const size_t sizeOfArray)
{
	for (size_t i = 0; i < sizeOfArray; i++)
	{
		if (arrayToCheck[i] == numberToCheck)
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

void pushToArray(unsigned int input, array<int, ::size> & arrayUsed)
{
	static size_t arrayIndex = 0;

	arrayUsed[arrayIndex] = input;

	arrayIndex++;
}