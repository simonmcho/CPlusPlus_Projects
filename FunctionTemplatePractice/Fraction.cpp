///////////////////////////////////////////
//COMP 2617 Assign 04
//Fraction.cpp
//
//Simon Cho (simmonson)
//Oct 14, 2017 (V 1.0.0)
///////////////////////////////////////////

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;

Fraction::Fraction()//default constructor
{
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(long long num, long long denom)//constructor with 2 arguments
	:numerator(num), denominator(denom)
{
	simplify();
	//empty body constructor
}

//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq(const Fraction & op)
{
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
				 //   will invoke gcd() function to reduce fraction
				 //   as much as possible

	return (*this); // returns the object which invoked the method
}

//Adds RHS to the Fraction object invoked with this method
const Fraction & Fraction::plusEq(const Fraction & op) 
{
	numerator = (op.denominator * numerator) + (op.numerator * denominator);
	denominator = denominator * op.denominator;

	simplify();
	return (*this);
}

//Subtracts RHS from the Fraction object invoked with this method
const Fraction & Fraction::minusEq(const Fraction & op) 
{
	numerator = (op.denominator * numerator) - (op.numerator * denominator);
	denominator = denominator * op.denominator;

	simplify();
	return (*this);
}

//Divides RHS into the Fraction object invoked with this method
const Fraction & Fraction::divideEq(const Fraction & op) 
{
	numerator *= op.denominator;
	denominator *= op.numerator;

	simplify();

	return (*this);
}

// Returns numerator
long long Fraction::getNum(void)const
{
	return numerator;
}

// Returns denominator
long long Fraction::getDenom(void)const
{
	return denominator;
}

// Outputs to standard output stream the Fraction object
void Fraction::display(void)const
{
	cout << numerator << '/' << denominator;
}

//Returns the negation of the Fraction object
Fraction Fraction::negate(void)const 
{
	long long tempNumerator;
	long long tempDenominator;

	//if both are negative, negate both
	if ((numerator < 0 && denominator < 0))
	{
		tempNumerator = -numerator;
		tempDenominator = -denominator;
	}
	//if both are positive or just numerator is positive. negate tempNumerator
	else if ((numerator >= 0 && denominator >= 0)|| numerator < 0)
	{
		tempNumerator = -numerator;
		tempDenominator = denominator;
	}
	//if denominator is negative, negate tempDenominator
	else if (denominator < 0)
	{
		tempNumerator = numerator;
		tempDenominator = -denominator;
	}//question for Bob - is it wrong to end if else statements with an else if?

	return Fraction(tempNumerator, tempDenominator);
}

// this method reduces the Fraction objects as much as possible
void Fraction::simplify()
{
	long long tempNumerator = numerator;
	long long tempDenominator = denominator;

	//ensures arguments entered into gcd template function are both positive
	if (tempNumerator < 0)
	{
		tempNumerator *= -1;
	}
	if (tempDenominator < 0)
	{
		tempDenominator *= -1;
	}

	numerator /= gcd(tempNumerator, tempDenominator);
	denominator /= gcd(tempNumerator, tempDenominator);

	//ensures denominator is positive. If negative, ensure numerator is negative
	if ( (denominator < 0 && numerator >= 0) || (denominator < 0 && numerator < 0) )
	{
		numerator *= -1;
		denominator *= -1;
	}
}
