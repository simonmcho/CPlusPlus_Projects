////////////////////////////////////////////////////////////////////////////////////////
//COMP 2617 Assignment One Solution: Employee.h
//Employee class definition. This file presents Employee's public interface. 
//Implementations are defined in Employee.cpp
//
//Simon Cho (simmonson)
//Sep 22, 2017, V1.0.0
////////////////////////////////////////////////////////////////////////////////////////

#include <string> // C++ standard string class

//Employee class definition
class Employee 
{
public:
	explicit Employee(std::string, std::string, int); //constructor initializes firstName, lastName, monthlySalary, respectively
	void setFirstName(std::string);//sets firstName
	void setLastName(std::string);//sets lastName
	void setMonthlySalary(int);//sets monthlySalary
	std::string getFirstName() const;//gets firstName
	std::string getLastName() const;//gets lastName
	int getMonthlySalary() const;//gets monthlySalary

private: 
	std::string firstName;
	std::string lastName;
	int monthlySalary;
};

