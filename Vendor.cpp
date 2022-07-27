#include "Vendor.h"


Vendor::Vendor()
{
	m_inventory.push_back("Broad sword");
	m_inventory.push_back("Assassin dagger");
	m_inventory.push_back("Chain mail");
	m_inventory.push_back("Big shield");
	m_inventory.push_back("Health potion");
}

void Vendor::buy_item(Character& player)
{
	int choice;

	display_inventory();

	std::cout << "Select an item to buy" << std::endl;
	std::cin >> choice;

	switch (choice)
	{
		case 1:
			if (player.m_gold > 0)
			{
				player.m_gold -= 50;
				player.m_inventory.push_back(m_inventory[choice - 1]);
				m_inventory.erase(m_inventory.begin());
				display_inventory();
			}
			else
				std::cout << "Not enough coin my guy" << std::endl;
			break;

		case 2:
			if (player.m_gold > 0)
			{
				player.m_gold -= 50;
				player.m_inventory.push_back(m_inventory[choice - 1]);
				m_inventory.erase(m_inventory.begin() + choice);
				display_inventory();
			}
			else
				std::cout << "Not enough coin my guy" << std::endl;
			break;

		case 3:
			if (player.m_gold > 0)
			{
				player.m_gold -= 50;
				player.m_inventory.push_back(m_inventory[choice - 1]);
				m_inventory.erase(m_inventory.begin() + choice);
				display_inventory();
			}
			else
				std::cout << "Not enough coin my guy" << std::endl;
			break;

		case 4:
			if (player.m_gold > 0)
			{
				player.m_gold -= 50;
				player.m_inventory.push_back(m_inventory[choice - 1]);
				m_inventory.erase(m_inventory.begin() + choice);
				display_inventory();
			}
			else
				std::cout << "Not enough coin my guy" << std::endl;
			break;

		case 5:
			if (player.m_gold > 0)
			{
				player.m_gold -= 50;
				player.m_inventory.push_back(m_inventory[choice - 1]);
				m_inventory.erase(m_inventory.end() - choice);
				display_inventory();
			}
			else
				std::cout << "Not enough coin my guy" << std::endl;
			break;
	}
}

void Vendor::sell_item()
{
	std::cout << "selling items" << std::endl;
}

void Vendor::display_inventory()
{
	for (int i = 0; i < m_inventory.size(); i++)
		std::cout << m_inventory[i] << std::endl;
}