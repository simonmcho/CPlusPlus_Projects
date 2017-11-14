//
// Calculate gross pay, net pay, pension and deductions for employees of Rogers Hostpital Supplies Company.
//
// Bob Langelaan
// Edited by Simon Cho, A00954121
// November 12, 2017
//

#include <iostream>
#include <string>
#include <conio.h>  // Required for _getch() function
#include <fstream>  // Required for file input/output
#include <iomanip> // Required for currency display

using namespace std;

//global constants

// One way to specify a file name:
const char * IN_FILE = "EmployeePayInput.txt";

// A second way to specify a file name:
#define OUT_FILE "EmployeePayOutput.txt"

int main()
{
	//Declare variables
	const char companyName[] = "Rogers Hospital Supplies Company";  //The company name
	long socialInsuranceNum;  // Will store social security number of employee
	int numberOfExemptions;  // Will store number of excemptions for employee
	
	unsigned int totalNumberOfEmployeesProcessed = 0; //Will store total number of employees
	double payRate,						              //Will store the pay rate for the employee
		hoursWorked,					              //Will store hours worked for the employee, 
		totalGrossPay = 0.0,		    		      //Will store total gross pay of all employees processed
		totalNetPay = 0.0,			      			  //Will store total net pay of all employees processed
		totalPension = 0.0,			    			  //Will store total pension of all employees processed
		totalDeductions = 0.0;					      //Will store total deductions of all employees processed

	const string inputDataError = "INPUT DATA ERROR:"; //Will store error message for console output

	//Define ifstream object and open file
	ifstream ins;
	ins.open(IN_FILE);

	//Check that file opened without any issues
	if (ins.fail())
	{
		cerr << "ERROR--> Unable to open input file : " << IN_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -1; //error return code
	}

	//Define ofstream object and open file
	ofstream outs;
	outs.open(OUT_FILE);

	//Check that file opened without any issues
	if (outs.fail())
	{
		cerr << "ERROR--> Unable to open output file : " << OUT_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -2; //error return code
	}

	//Write out the Company Name as header
	outs << companyName << '\n';
	outs << "---------------------------------\n\n"; 
	outs << "Social insurance no." << setw(12) << "gross pay" << setw(11) << "net pay" << setw(11) << "pension" << setw(14) << "deductions";
	outs << "\n--------------------------------------------------------------------\n";

	// Read in first social security number
	ins >> socialInsuranceNum;

	// Process data until end of file is reached
	while (!ins.eof())
	{
		// Read in other data for the employee
		ins >> payRate >> numberOfExemptions >> hoursWorked; 

		//Check to ensure SIN is valid and the pay rate, number of exemptions, and hours worked is non-negative
		if (socialInsuranceNum <= 999999999 && socialInsuranceNum > 99999999 &&
			payRate >= 0 && payRate <= 99.99 &&
			numberOfExemptions >= 0 && numberOfExemptions <= 19 &&
			hoursWorked >= 0 && hoursWorked <= 54)
		{
			double grossPay = (hoursWorked <= 40) ? (payRate * hoursWorked) : (payRate * 40) + ( (payRate * 1.5) * (hoursWorked - 40) ), //  store gross pay
					taxableIncome = ( (grossPay - (14.00 * numberOfExemptions) - 11.00) > 0) ? (grossPay - (14.00 * numberOfExemptions) - 11.00) : 0.0,// store taxable income
					federalTax = taxableIncome * (0.14 + (0.00023 * taxableIncome)), // store federal tax
					provTax = 0.35 * federalTax, //  store provincial tax
					pensionPercentage = 0.077, //Pension percentage
					pension = (grossPay * pensionPercentage < 16.50) ? (grossPay * pensionPercentage) : 16.50, // store pension
					deductions = (grossPay > 0) ? (pension + federalTax + provTax) : 0.0, // store all deductions
					netPay = grossPay - deductions;		   // store net pay

			//increment totals as needed
			totalNumberOfEmployeesProcessed++; 
			totalGrossPay += grossPay;
			totalNetPay += netPay;
			totalPension += pension;
			totalDeductions += deductions;

			//Write to file
			outs << socialInsuranceNum << setw(23) << fixed << setprecision(2) << grossPay << setw(11) << setw(11) << netPay << setw(11) << setw(11) << pension << setw(14) << deductions << '\n';
		}
		else 
		{//assign specific values depending on the invalid entry
			if (!(socialInsuranceNum <= 999999999 && socialInsuranceNum > 99999999))//bad SIN
			{
				cout << setw(10) << socialInsuranceNum << setw(22) << inputDataError << setw(27) << "Invalid social security #" << endl;
			}
			if (!(payRate >= 0 && payRate <= 99.99))//bad pay rate
			{
				cout << setw(10) << socialInsuranceNum << setw(22) << inputDataError << setw(20) << "Invalid pay rate: " << fixed << setprecision(2) <<payRate << endl;
			}
			if (!(numberOfExemptions >= 0 && numberOfExemptions <= 19))//bad number of exemptions
			{
				cout << setw(10) << socialInsuranceNum << setw(22) << inputDataError << setw(31) << "Invalid number of exemptions " << numberOfExemptions << endl;
			}
			if (!(hoursWorked >= 0 && hoursWorked <= 54))//bad number of hours worked
			{
				cout << setw(10) << socialInsuranceNum << setw(22) << inputDataError << setw(24) << "Invalid hours worked: " << fixed << setprecision(2) << hoursWorked << endl;
			}
		}

		// Read in next social security number
		ins >> socialInsuranceNum;
	}

	//Write to file the summary and its details
	outs << "\n\n\nSummary\n" << "-------\n";
	outs << "\nNumber of employees processed:" << setw(1) << "\t\t\t" << setw(8) << totalNumberOfEmployeesProcessed << '\n';
	outs << "Total gross pay for all employees:" << setw(1) << "\t\t" << setw(8) << totalGrossPay << '\n';
	outs << "Total net pay for all employees:" << setw(1) << "\t\t" << setw(8) << totalNetPay << '\n';
	outs << "Total pension withheld for all employees:" << setw(1) << "\t" << setw(8) << totalPension << '\n';
	outs << "Total deductions for all employees:" << setw(1) << "\t\t" << setw(8) << totalDeductions << '\n';

	// Close files
	ins.close();
	outs.close();

	_getch(); // causes execution to pause until char is entered

}