#include "stdafx.h"
#include "data.h"
#include "nlohmann\json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

Data::Data()
{
	ifstream file("in.json");
	json input;
	file >> input;
	if (input["shops_count"].get<int>() != 0)
	{
		shopsCount = input["shops_count"].get<int>();
		shops = new Shop[input["shops_count"].get<int>()];
		int i = -1;
		for (auto& element : input["shops"])
		{
			i++;
			shops[i] = *(new Shop((element),element["name"].get<string>()+"numRC"));

			for (auto& employee : element["employees"])
				shops[i].AddEmployees(employee);

			for (auto& product : element["products"])
				shops[i].AddProduct(product);
		}
	}
}


Data::~Data()
{
	ofstream file("in.json");
	json output;
	output["shops_count"] = shopsCount;
	
	for (int i = 0; i < shopsCount; i++)
	{
		json shop;
		shop["name"] = shops[i].GetName();
		shop["address"] = shops[i].GetAddress();
		shop["identifier"] = shops[i].GetIdentifier();
		shop["employees_count"] = shops[i].GetEmployeesCount();
		json products;
		for (int j = 0; j < shops[i].GetProductsCount(); j++)
		{
			json product;
			product["name"] = shops[i].GetProd()[j].GetName();
			product["price"] = shops[i].GetProd()[j].GetPrice();
			product["count"] = shops[i].GetProd()[j].GetCount();
			product["identifier"] = shops[i].GetProd()[j].GetIdentifier();
			products.push_back(product);
		}
		shop["products"] = products;
		json employees;
		for (int j = 0; j < shops[i].GetEmployeesCount(); j++)
		{
			json employee;
			employee["position"] = shops[i].GetEmp()[j].GetPos();
			employee["name"] = shops[i].GetEmp()[j].GetName();
			employee["salary"] = shops[i].GetEmp()[j].GetSalary();
			employee["identifier"] = shops[i].GetEmp()[j].GetIdentifier();
			employees.push_back(employee);
		}

		shop["employees"] = employees;
		shop["products"] = products;
		output["shops"].push_back(shop);
	}
	file << output.dump(4);


	delete[] shops;
	file.close();
}
int Data::SearchPos(string identifier)
{
	for (int i = 0; i < shopsCount; i++)
	{
		if (shops[i].GetIdentifier() == identifier) return i;
	}
	return -1;
}
json Data::AddShop(json input)
{
	json output;
	if ((input.count("name") == 1) && (input.count("address") == 1))
	{
		Shop* shopsCopy = shops;
		shopsCount++;
		shops = new Shop[shopsCount];

		for (int i = 0; i < shopsCount - 1; i++)
			shops[i] = shopsCopy[i];

		shops[shopsCount - 1] = *(new Shop(input, (input["name"].get<string>() + "numRC")));
		output["status"] = "OK";
		output["shop_identifier"] = shops[shopsCount - 1].GetIdentifier();
	}
	else
		output["status"] = "FAIL";
	
	return output;
}
json Data::DeleteShop(json input)
{
	json status;
	if (input.count("identifier") == 1)
	{
		int pos = SearchPos(input["identifier"].get<string>());
		if (pos != -1)
		{
			shopsCount--;
			for (int i = pos; i < shopsCount; i++)
				shops[i] = shops[i + 1];

			status["status"] = "OK";
		}
		else
			status["status"] = "FAIL";
	}
	else
		status["status"] = "FAIL";
	
	return status;
}

json Data::ShowShop(json input)
{
	json status;
	if (input.count("identifier") == 1)
	{
		int pos = SearchPos(input["identifier"].get<string>());
		status["identifier"] = input["identifier"].get<string>();
		if (pos != -1)
		{
			shops[pos].ShowShop();
			status["status"] = "OK";
		}
		else
			status["status"] = "FAIL";
	}
	else
		status["status"] = "FAIL";
		
	return status;
}
json Data::AddEmp(json input)
{
	json status;
	if (input.count("identifier") == 1 && input.count("name") == 1 && input.count("salary") == 1 && input.count("position") == 1)
	{
		int pos = SearchPos(input["identifier"].get<string>());
		if (pos != -1)
		{
			shops[pos].AddEmployees(input);
			status["status"] = "OK";
			status["identifier"] = shops[pos].GetEmp()[shops[pos].GetEmployeesCount() - 1].GetIdentifier();
		}
		else
			status["status"] = "FAIL";
	}
	else
		status["status"] = "FAIL";
	
	return status;
}
json Data::AddProd(json input)
{
	json status;
	if (input.count("identifier") == 1 && input.count("name") == 1 && input.count("price") == 1 && input.count("count") == 1)
	{
		int pos = SearchPos(input["identifier"].get<string>());
		if (pos != -1)
		{
			shops[pos].AddProduct(input);
			status["status"] = "OK";
			status["identifier"] = shops[pos].GetProd()[shops[pos].GetProductsCount() - 1].GetIdentifier();
		}
		else
			status["status"] = "FAIL";
	}
	else
		status["status"] = "FAIL";
	
	return status;
}
json Data::DeleteEmp(json input)
{
	json status;
	if (input.count("identifier") == 1 && input.count("identifier_shop") == 1)
	{
		int pos = SearchPos(input["identifier_shop"].get<string>());
		if (pos != -1)
		{
			shops[pos].DeleteEmployee(input["identifier"].get<string>());
			status["status"] = "OK";
		}
		else
			status["status"] = "FAIL";
	}
	else
		status["status"] = "FAIL";
	
	return status;
}
json Data::DeleteProd(json input)
{
	json status;
	if (input.count("identifier") == 1 && input.count("identifier_shop") == 1)
	{
		int pos = SearchPos(input["identifier_shop"].get<string>());
		if (pos != -1)
		{
			shops[pos].DeleteProduct(input["identifier"].get<string>());
			status["status"] = "OK";
		}
		else
			status["status"] = "FAIL";
	}
	else
		status["status"] = "FAIL";
	
	return status;
}
json Data::ShowEmployees(json input)
{
	json status;
	if (input.count("identifier") == 1)
	{
		int pos = SearchPos(input["identifier"].get<string>());
		status["identifier"] = input["identifier"].get<string>();
		if (pos != -1)
		{
			shops[pos].ShowEmployees();
			status["status"] = "OK";
		}
		else
			status["status"] = "FAIL";
	}
	else
		status["status"] = "FAIL";
	
	return status;
}
json Data::ShowProducts(json input)
{
	json status;
	if (input.count("identifier") == 1)
	{
		int pos = SearchPos(input["identifier"].get<string>());
		status["identifier"] = input["identifier"].get<string>();
		if (pos != -1)
		{
			shops[pos].ShowProducts();
			status["status"] = "OK";
		}
		else
			status["status"] = "FAIL";
	}
	else
		status["status"] = "FAIL";
	
	return status;
}
void Data::ShowShops()
{
	for (int i = 0; i < shopsCount; i++)
	{
		cout << "name: " << shops[i].GetName() << " identifier: " << shops[i].GetIdentifier() << endl;
	}
}
