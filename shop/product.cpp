#include "stdafx.h"
#include "product.h"
#include <iostream>;


Product::Product(string name, int price, int count, string identifier)
{
	this->name = name;
	this->price = price;
	this->count = count;
	this->identifier = identifier;
}
void Product::ShowProd()
{
	cout << "name: " << name << " price: " << price << " count: " << count << " ident: " << identifier << endl;
}
string Product::GetIdentifier()
{
	return identifier;
}
int Product::GetCount()
{
	return count;
}
string Product::GetName()
{
	return name;
}
int Product::GetPrice()
{
	return price;
}
Product::Product()
{
}
Product::~Product()
{
}
