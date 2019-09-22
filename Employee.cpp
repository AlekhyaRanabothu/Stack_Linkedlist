#include <cstdlib>
#include <iostream>
#include <string>
#include "Employee.h"
#include <sstream>
#include <cstring>

using namespace std;

Employee::Employee()   //default constructor intialize an empty employee record
{
    ID = 0;
    lastname = "";
    firstname = "";
}

Employee::Employee(int IdNum, std::string last, std::string first)// to create an Employee with the specified id,firstnameand lastname
{
    ID = IdNum;
    lastname = last;
    firstname = first;
}
Employee::Employee(const Employee &person)//copy constructor of Employee
{
    ID = person.ID;
    lastname = person.lastname;
    firstname = person.firstname;
}

Employee::~Employee()//destructor of Employee class
{
    cout << "Employee is deleted" << endl;
}

void Employee::setFirstName(string first) //to set the employee first name
{
    firstname = first;
}

void Employee::setLastName(string last)//to set the  employee lastname
{
    lastname = last;
}

void Employee::setID(int IdNum)//sets the Employee ID
{
    ID = IdNum;
}

int Employee::getID() const//read the EmployeeID
{
    return ID;
}

string Employee::getLastName() const //read the Employee lastname
{
    return lastname;
}

string Employee:: getFirstName() const//read the Employee firstname
{
    return firstname;
}

ostream& operator<<(ostream &outs, Employee &person)// outputs the Employee record
{
    outs << "ID:" << person.getID() << "\n" << "FirstName:" << person.getFirstName() << "\n" << "Lastname:" << person.getLastName() << endl;
    return outs;
}

istream& operator>>(istream &ins, Employee &person)//reads the line of Employee record,tokenizes and stores the ID,firstname and lastname line by line
{
    char input[100];
    ins.getline(input, sizeof(input));
    string details(input);
    stringstream ss(details);
    string token;
    char delimiter = ' ';
    string emp_details[3] = {};
    int i=0;
    while(getline(ss, token, delimiter)) {
        emp_details[i] = token;
        i++;
    }
 
    person.setLastName(emp_details[0]);
    person.setFirstName(emp_details[1]);
    person.setID(stoi(emp_details[2]));

    return ins;
}

bool operator ==(const Employee& person1, const Employee& person2)//to check if two employee records are equal
{
    return
            (person1.getID( ) == person2.getID( ))
            &&
            (person1.getLastName( ).compare(person2.getLastName( ))== 0)
            &&
            (person1.getFirstName().compare(person2.getFirstName( ))== 0);
}
