////////////////////////////////////////////////////////////////////////////////////////
//COMP 2617 Assignment One Solution: Employee.cpp
//Employee member-function definitions. This file contains implementation of the member functions prototyped in Employee.h
//
//Simon Cho (simmonson)
//Sep 22, 2017, V1.0.0
////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Employee.h" //include definition of class Employee

using namespace std; // use std namespace 

//constructor initializes data members in Employee class
Employee::Employee( string _firstName, string _lastName, int _monthlySalary )
	:firstName( _firstName ), lastName( _lastName ), monthlySalary( _monthlySalary ) //member initialization list to initialize the respective data members
{
	//Verifying so that firstName is longer than 2 characters, if not, show warning
	if (_firstName.length() > 2)
	{
		firstName = _firstName;
	}
	else
	{
		cout << "\nWarning - invalid length string entered for first name in ctor: " << _firstName << endl;
		cout << "The string that was entered will be used for now." << endl;
	}

	//Verifying so that lastName is longer than 2 characters, if not, show warning
	if ( _lastName.length() > 2 )
	{
		lastName = _lastName;
	}
	else
	{
		cout << "\nWarning - invalid length string entered for last name in ctor: " << _lastName << endl;
		cout << "The string that was entered will be used for now." << endl;
	}

	//Verifying that salary is equal to or greater than zero. If not, show warning and set salary to 0
	if ( _monthlySalary >= 0 )
	{
		monthlySalary = _monthlySalary;
	}
	else
	{
		monthlySalary = 0;

		cout << "\nInvalid salary amount specified in ctor: $" << _monthlySalary << endl;
		cout << "Salary set to $0 instead." << endl;
	}

}//end Employee constructor

//sets firstName
void Employee::setFirstName( string _firstName )
{
	if ( _firstName.length() > 2 ) {
		firstName = _firstName;
	}
	else
	{
		cout << "\nERROR - invalid length string entered for first name in setFirstName(): " << _firstName << endl;
		cout << "The first name was left unchanged: " << firstName << endl;
	}
}

//sets lastName
void Employee::setLastName( string _lastName )
{
	if ( _lastName.length() > 2 ) {
		lastName = _lastName;
	}
	else
	{
		cout << "\nERROR - invalid length string entered for last name in setLastName(): " << _lastName << endl;
		cout << "The last name was left unchanged: " << lastName << endl;
	}
}

//sets monthlySalary
void Employee::setMonthlySalary( int _monthlySalary )
{
	if ( _monthlySalary >= 0 )
	{
		monthlySalary = _monthlySalary;
	}
	else
	{
		cout << "\nERROR - Invalid salary amount specified : $" << _monthlySalary << endl;
		cout << "Salary was left unchanged at: $" << monthlySalary << endl;
	}
}

//gets firstName
string Employee::getFirstName() const
{
	return firstName;
}

//gets lastName
string Employee::getLastName() const 
{
	return lastName;
}

//gets monthlySalary
int Employee::getMonthlySalary() const 
{
	return monthlySalary;
}
