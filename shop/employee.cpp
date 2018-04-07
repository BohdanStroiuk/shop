#include "stdafx.h"
#include "employee.h"
#include <iostream>


Employee::Employee(string position, string name, int salary, string identifier)
{
	this->position = position;
	this->name = name;
	this->salary = salary;
	this->identifier = identifier;
}
Employee::Employee()
{

}
void Employee::ShowEmp()
{
	cout << "position: " <<position<<" name: "<<name<<" salary: "<<salary<<" identifier: "<<identifier<<endl;
}
string Employee::GetIdentifier()
{
	return identifier;
}
string Employee::GetName()
{
	return name;
}
string Employee::GetPos()
{
	return position;
}
int Employee::GetSalary()
{
	return salary;
}


Employee::~Employee()
{
}
