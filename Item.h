#pragma once
#include <iostream>

 struct Item
{
	std::string  m_name;
	unsigned int m_price;
	unsigned int m_item_level;
	unsigned int m_rarity;
	bool		 m_enemy_drop;
	bool		 m_vendor_drop;


	virtual void display_item_options();
};
