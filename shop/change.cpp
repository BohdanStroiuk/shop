#include "stdafx.h"
#include "change.h"
#include "nlohmann\json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

Shop* Load()
{
	ifstream file("in.json");
	json input;
	file >> input;
	Shop* shops = new Shop[input["shops_count"].get<int>()];
	int i = -1;
	for (auto& element : input["shops_list"])
	{
		i++;
		shops[i] = *(new Shop(element));
		for (auto& employee : element["employeees"])
			shops[i].AddEmployees(employee);

		for (auto& product : element["products"])
			shops[i].AddProduct(product);
	}
	return shops;
};