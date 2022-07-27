#pragma once
#include <iostream>
#include <vector>

#include "Character.h"

struct Vendor
{
	std::string m_name;
	unsigned int m_level;
	std::vector<std::string> m_inventory;

	Vendor();

	// Functions for trading items. 
	void buy_item(Character& player);
	void sell_item();
	void display_inventory();
};
