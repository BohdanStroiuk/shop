#pragma once
#include "employee.h"
#include "product.h"
#include <iostream>
#include "nlohmann\json.hpp"

using namespace std;
using json = nlohmann::json;

using namespace std;

class Shop
{
private:
	string name;
	string address;
	int employeesCount = 0;
	int productsCount = 0;
	Product* products;
	Employee* employees;
	string identifier;
public:
	Shop(json, string);
	Shop();
	void AddProduct(json);
	void AddEmployees(json);
	void DeleteProduct(string);
	void DeleteEmployee(string);
	void ShowProducts();
	void ShowEmployees();
	void ShowShop();
	string GetName();
	string GetAddress();
	string GetIdentifier();
	int GetEmployeesCount();
	int GetProductsCount();
	Product* GetProd();
	Employee* GetEmp();
	~Shop();
};

