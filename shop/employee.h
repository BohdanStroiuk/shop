#pragma once
#include <string>

using namespace std;

class Employee
{
private:
	string position;
	string name;
	int salary;
	string identifier;

public:
	Employee(string, string, int, string);
	void ShowEmp();
	string GetIdentifier();
	string GetPos();
	string GetName();
	int GetSalary();
	Employee();
	~Employee();
};

