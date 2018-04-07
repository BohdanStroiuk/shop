#pragma once
#include "shop.h"
#include "nlohmann\json.hpp"
using json = nlohmann::json;
class Data
{
private:
	int SearchPos(string);
public:
	int shopsCount;
	Shop* shops;
	json AddShop(json);
	json DeleteShop(json);
	json AddEmp(json);
	json AddProd(json);
	json DeleteEmp(json);
	json DeleteProd(json);
	json ShowShop(json);
	json ShowEmployees(json);
	json ShowProducts(json);
	void ShowShops();
	Data();
	~Data();
};

