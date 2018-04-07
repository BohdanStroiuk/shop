#include "stdafx.h"
#include "shop.h"
#include "employee.h"
#include "nlohmann\json.hpp"
using json = nlohmann::json;
using namespace std;
Shop::Shop(json inputJson, string newIdentifier)
{
	name = inputJson["name"].get<string>();
	address = inputJson["address"].get<string>();
	identifier = newIdentifier;
	employees = new Employee[1];
	products = new Product[1];
}
Shop::Shop() {};
void Shop::AddEmployees(json inputEmpJson)
{
	Employee* employeesCopy = employees;
	employeesCount++;
	employees = new Employee[employeesCount];

	for (int i = 0; i < employeesCount-1; i++)
		employees[i] = employeesCopy[i];

	*(employees + employeesCount - 1) = *(new Employee(inputEmpJson["position"].get<string>(), inputEmpJson["name"].get<string>(),inputEmpJson["salary"], inputEmpJson["name"].get<string>() + "EMP"));
}
void Shop::AddProduct(json inputProdJson)
{
	Product* productsCopy = products;
	productsCount++;
	products = new Product[productsCount];
	for (int i = 0; i < productsCount - 1; i++)
		products[i] = productsCopy[i];

	*(products + productsCount - 1) = *(new Product(inputProdJson["name"].get<string>(), inputProdJson["price"].get<int>(), inputProdJson["count"].get<int>(), inputProdJson["name"].get<string>() + "PROD"));


}
void Shop::DeleteProduct(string identifier)
{
	int position = -1;
	for (int i = 0; i < productsCount; i++)
		if (products[i].GetIdentifier() == identifier)
		{
			position = i;
			break;
		}
	if (position != -1)
	{
		productsCount--;
		for (int i = position; i < productsCount; i++)
			products[i] = products[i + 1];
	}
}
void Shop::DeleteEmployee(string identifier)
{
	int position = -1;
	for (int i = 0; i < employeesCount; i++)
		if (employees[i].GetIdentifier() == identifier)
		{
			position = i;
			break;
		}
	if (position != -1)
	{
		employeesCount--;
		for (int i = position; i < employeesCount; i++)
			employees[i] = employees[i + 1];
	}
}
void Shop::ShowProducts()
{
	for (int i = 0; i < productsCount; i++)
		products[i].ShowProd();
}
void Shop::ShowEmployees()
{
	for (int i = 0; i < employeesCount; i++)
		employees[i].ShowEmp();
}
void Shop::ShowShop()
{
	cout << "name: " << name << endl;
	cout << "address: " << address << endl;
	cout << "identifier: " << identifier << endl;
	cout << "employees: " << endl;
	ShowEmployees();
	cout << "products: " << endl;
	ShowProducts();
}
string Shop::GetName()
{
	return name;
}
string Shop::GetAddress()
{
	return address;
}
string Shop::GetIdentifier()
{
	return identifier;
}
int Shop::GetProductsCount()
{
	return productsCount;
}
int Shop::GetEmployeesCount()
{
	return employeesCount;
}
Product* Shop::GetProd()
{
	return products;
}
Employee* Shop::GetEmp()
{
	return employees;
}
Shop::~Shop()
{
	delete[] employees;
	delete[] products;

}
