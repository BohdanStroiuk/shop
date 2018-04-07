#pragma once
#include "shop.h"
#include "nlohmann\json.hpp"
using json = nlohmann::json;

Shop* Load();
void Save(Shop*);
