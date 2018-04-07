#pragma once
#include <string>

using namespace std;
class Product
{
private:
	string name;
	int price;
	int count;
	string identifier;
public:
	Product(string, int, int, string);
	string GetIdentifier();
	string GetName();
	int GetPrice();
	int GetCount();
	Product();
	~Product();
	void ShowProd();
	
	
};

