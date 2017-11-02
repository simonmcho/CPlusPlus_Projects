/////////////////////////////////////
//main.cpp
//
//Simon Cho (simmonson)
//Oct 2, 2017
/////////////////////////////////////

//using C++ Standard Libraries
#include <iostream>
#include <cctype>

using namespace std;

int main()//main
{
	unsigned int counter = 1;
	char c;
    unsigned int previousNumber;
	unsigned int currentNumber;
	unsigned int sum;

	std::cout << "10 Roman numeral values will be input and converted into"
		<< "\ntheir equivalent Hindu - Arabic numeric values.\n" << endl;//description to user

	while (counter <= 10)//loop through 10 times
	{
		cout << "Input Roman numeral # " << counter << ": ";//prompt user;
		sum = 0;//reset sum to zero for every conversion
		previousNumber = 0;

		while ( c = cin.get() )//while there is cin.get()
		{
			
			if (c == '\n')//break out of loop if new line or invalid char
			{
				cout << " = " << sum << '\n' << endl;
				break;
			}
			
			c = toupper(c);//uppercase all inputs
			std::cout << c;//print out c

			switch (c)//switch cases for roman numeral conversions
			{
			case 'I':
				currentNumber = 1;	
				break;
			case 'V':
				currentNumber = 5;		
				break;
			case 'X':
				currentNumber = 10;
				break;
			case 'L':
				currentNumber = 50;			
				break;
			case 'C':
				currentNumber = 100;	
				break;
			case 'D':
				currentNumber = 500;
				break;
			case 'M':
				currentNumber = 1000;
				break;
			default:
				currentNumber = 0;
			}//end of switch case for roman numeral conversions

			if (currentNumber == 0)//break out of loop if character is invalid, clear and flush cin.get()
			{
				std::cout << " Error - last character was not valid!!!" << '\n' << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
            
           		if(previousNumber == 0)//add to sum if previousNumber is 0
        		{
       			        previousNumber = currentNumber;
        		        sum += currentNumber;
            		}
            		else if(currentNumber <= previousNumber)//add to sum with current number
            		{
                		sum += currentNumber;
                		previousNumber = currentNumber;
            		}
            		else //add to sum the current number minus 2 times the previous number (to counteract the first if statement)
            		{
                		sum += currentNumber - (2 * previousNumber);
                		previousNumber = 0;
            		}

            
		}//end of while(cin.get(c)) loop
		
		
		counter++;//ensure incrementation of counter to avoid infinite loop
	}//end of while loop for counter

	cout << "THAT'S ALL FOLKS :)\n" << endl;
	system("pause");
	cout << endl;
}//end of main
