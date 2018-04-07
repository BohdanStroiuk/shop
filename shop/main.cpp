// shop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "data.h"
#include "change.h"
#include <iostream>
#include "nlohmann\json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;


inline constexpr std::uint32_t StrRead(const char* str, std::uint32_t hash = 2166136261UL) 
{
	return *str ? StrRead(str + 1, (hash ^ *str) * 16777619ULL) : hash;
}
int main()
{
	Data* dataBase = new Data();
	
	
	
	string action = "";
	while (action != "exit")
	{
		json inputJson;
		cin >> inputJson;
		if (inputJson.count("action") == 1)
		{
			action = inputJson["action"].get<string>();
			switch (StrRead(action.c_str()))
			{
			case StrRead("add_shop"):
			{
				cout << dataBase->AddShop(inputJson) << endl;
				break;
			}
			case StrRead("remove_shop"):
			{
				cout << dataBase->DeleteShop(inputJson) << endl;
				break;
			}
			case StrRead("get_shop"):
			{
				cout << dataBase->ShowShop(inputJson) << endl;
				break;
			}
			case StrRead("add_employee"):
			{
				cout << dataBase->AddEmp(inputJson) << endl;
				break;
			}
			case StrRead("add_product"):
			{
				cout << dataBase->AddProd(inputJson) << endl;
				break;
			}
			case StrRead("remove_product"):
			{
				cout << dataBase->DeleteProd(inputJson) << endl;
				break;
			}
			case StrRead("remove_employee"):
			{
				cout << dataBase->DeleteEmp(inputJson) << endl;
				break;
			}
			case StrRead("get_products"):
			{
				cout << dataBase->ShowProducts(inputJson) << endl;
				break;
			}
			case StrRead("get_employees"):
			{
				cout << dataBase->ShowEmployees(inputJson) << endl;
				break;
			}
			case StrRead("get_list"):
			{
				dataBase->ShowShops();
				break;
			}
			case StrRead("exit"):
			{
				dataBase->~Data();
				return 0;
				break;
			}
			default:
			{
				cout << "ERROR" << endl;
				break;
			}
			};
			action = "";
		}
		else cout << "ERROR" << endl;
		
	}
}

