//////////////////////////////////////////////////////////////
//COMP 2617 Assignment 3 - Multiplication Test
//main.cpp
//
//Simon Cho (simmonson)
//Oct 7, 2017 V 1.0.0
//
//
//README
//Some comments are for my own learning
//So when comments are more descriptive about libraries, etc.
//It is to help myself study and remember better
//////////////////////////////////////////////////////////////

//using C++ standard libraries
#include <iostream>
#include <string>
#include <ctime> //contains features to get and manipulate date and time information
//#include <random> //contains C++11 random number generating features

//global variables
bool newQuestion = true;
unsigned int userAnswer;
unsigned int firstNumber;
unsigned int secondNumber;
unsigned int actualAnswer;
unsigned int randomResponse;
std::string responseToUserAnswer;

//ENUMS
enum class Success { VERYGOOD, EXCELLENT, NICEWORK, KEEPUP };//ENUM values for re-affirming if user answer is correct
enum class Retry { TRYAGAIN, WRONG, DONOTGIVEUP, KEEPTRYING };//ENUM values for re-prompting if user answer is incorrect

//ENUM instantiation
Success answerSuccess;
Retry   answerRetry;

//const strings for prompts
const std::string promptOne   = "How much is ";
const std::string promptTwo   = " times ";
const std::string promptThree = " (-1 to End)? ";
const std::string goodBye     = "That's all for now. Bye.";

/*Using C++11 
std::default_random_engine engine(static_cast<unsigned int>(time(0)));//seed with current time
std::uniform_int_distribution<unsigned int> randomQuestionInt(0, 9);//specify a range for the random number generator for question
std::uniform_int_distribution<unsigned int> randomResponseInt(1, 4);//specify a range for random response for user answer
*/


//function to create and display random multiplication question
void displayRandomMultiplicationQuestion()
{
	firstNumber  = rand() % 10;
	secondNumber = rand() % 10;
	actualAnswer = firstNumber * secondNumber;

	std::cout << promptOne << firstNumber << promptTwo << secondNumber << promptThree;
}//end of displayRandomMultiplicationQuestion function

//function to display if user input was the correct answer
void correctMessage(unsigned int response)
{
	switch (response)//switch case to assign a Success Enum value
	{
	case 1:
		answerSuccess = Success::VERYGOOD;
		break;
	case 2:
		answerSuccess = Success::EXCELLENT;
		break;
	case 3:
		answerSuccess = Success::NICEWORK;
		break;
	case 4:
		answerSuccess = Success::KEEPUP;
		break;
	default:
		answerSuccess = Success::VERYGOOD;
	}

	if (answerSuccess == Success::VERYGOOD)//Determine what statement to show to user depending on Enum value
	{
		responseToUserAnswer = "Very good!";
	}
	else if (answerSuccess == Success::EXCELLENT)
	{
		responseToUserAnswer = "Excellent!";
	}
	else if (answerSuccess == Success::NICEWORK)
	{
		responseToUserAnswer = "Nice work!";
	}
	else
	{
		responseToUserAnswer = "Keep up the good work!";
	}

	std::cout << responseToUserAnswer << "\n" << std::endl;
}//end of correctMessage function

//function to display if user input was the incorrect answer
void incorrectMessage(unsigned int response)
{
	switch (response)//switch case to assign a RETRY Enum value
	{
	case 1:
		answerRetry = Retry::TRYAGAIN;
		break;
	case 2:
		answerRetry = Retry::WRONG;
		break;
	case 3:
		answerRetry = Retry::DONOTGIVEUP;
		break;
	case 4:
		answerRetry = Retry::KEEPTRYING;
		break;
	default:
		answerRetry = Retry::TRYAGAIN;
	}

	if (answerRetry == Retry::TRYAGAIN)//Determine what statement to show to user depending on Enum value
	{
		responseToUserAnswer = "No. Please try again.";
	}
	else if (answerRetry == Retry::WRONG)
	{
		responseToUserAnswer = "Wrong. Try once more.";
	}
	else if (answerRetry == Retry::DONOTGIVEUP)
	{
		responseToUserAnswer = "Don't give up!!";
	}
	else
	{
		responseToUserAnswer = "No. Keep trying.";
	}

	std::cout << responseToUserAnswer << "\n? ";
}//end of incorrectMessage function

//main function
int main() {

	srand(time(0));//provide a new seed that allows a more random generation than pseudo-random

	std::cout << "Enter -1 to End." << std::endl;//first line

	while (userAnswer != -1)//Continue loop as long as user's answer is not -1
	{
		//show random question as long as newQuestion is true
		if (newQuestion)
		{
			displayRandomMultiplicationQuestion();
		}

		std::cin >> userAnswer;//store in buffer user's input

		if (userAnswer == -1)//if user's input is -1 continue to end of loop...not recommended to use continue so look at solution for better alternative
		{
			continue;
		}

		if (userAnswer == actualAnswer)//invoke correctMessage function if user input is the correct answer
		{
			randomResponse = 1 + (rand() % 4); //random generation every answer
			correctMessage(randomResponse);
			newQuestion = true;//ensure newQuestion is true to invoke displayRandomMultiplicationQuestion function again
		} 
		else//invoke incorrectMessage function if user input is the incorrect answer
		{
			randomResponse = 1 +(  rand() % 4 );//random generation every answer
			incorrectMessage(randomResponse);
			newQuestion = false;//assign value of false to ensure displayRandomMultiplicationQuestion does not run
		}
	}

	std::cout << "\n" << goodBye << std::endl;//Tell user that it's the end of the program
	system("pause");

}//end of main
