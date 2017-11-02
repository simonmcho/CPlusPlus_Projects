///////////////////////////////////////////
//COMP 2617 Assign 04
//GCD.h
//
//Simon Cho (simmonson)
//Oct 14, 2017 (V 1.0.0)
///////////////////////////////////////////

template < typename T >
T gcd(T value1, T value2)//template function to return greatest common denominator
{
	T result = 1;//initialize result

	//Ensure we loop through all possible values up to the smaller of the 2 values, inclusive
	for ( int i = 2; i <= ( (value1 < value2) ? value1 : value2); i++ )
	{
		if (value1 % i == 0 && value2 % i == 0)
		{
			result = i;
		}
	}//end of for loop

	return result;//return greatest common denominator
}