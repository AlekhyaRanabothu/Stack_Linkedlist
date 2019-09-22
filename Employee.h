
#ifndef _Employee_
#define _Employee_

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Employee{

public:
	Employee();//default constructor
	Employee(int IdNum, std::string last, std::string first);//to create a new Employee
	Employee(const Employee &person);//copy constructor
	~Employee();//destructor
	void setFirstName(string first);//set firstname
	void setLastName(string last);//set lastname
	void setID(int IdNum);//set ID
	int getID() const;//get Employee ID
	std::string getFirstName() const;//get Firstname
	std::string getLastName() const;//get lastname
	friend std::ostream& operator<<(std::ostream &outs, Employee &person);// read the record from inputstream
	friend std::istream& operator>>(std::istream &ins, Employee &person);//outputs the Employee record
    friend bool operator ==(const Employee& p1, const Employee& p2);//check if two employees are equal
private:
	int ID;//Employee ID
	std::string lastname;//Employee lastname
	std::string firstname;//Employee firstname


};


#endif
