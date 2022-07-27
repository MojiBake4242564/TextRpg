#include "Character.h"

void Character::display_stats()
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Health: " << m_health << std::endl;
	std::cout << "Chance to hit: " << m_attack_rating << std::endl;
	std::cout << "Chance to evade: " << m_defense_rating << std::endl;
	std::cout << "Damage: " << m_attack_power << std::endl;
	std::cout << "Gold: " << m_gold << std::endl;
	std::cout << "Current experience: " << m_experience << std::endl;
	std::cout << "Level: " << m_level << std::endl;
	std::cout << std::endl;
}

// Garbage formula to make sure it works
void Character::level_up()
{
	if (m_level < MAX_LEVEL)
	{
		m_level++;
		m_health += 10;
		m_attack_rating += 10;
		m_defense_rating += 10;
		m_attack_power += 10;
	}
}

void Character::take_damage(int damage)
{
	if (m_health > 0)
		m_health -= damage;

	if (m_health <= 0)
		std::cout << " You are dead !" << std::endl;
}

std::string Character::get_save_data()
{
	std::stringstream ss;

	ss << "Health: " << m_health << std::endl;
	ss << "Attack: " << m_attack_rating << std::endl;
	ss << "Defense: " << m_defense_rating << std::endl;
	ss << "Damage: " << m_attack_power << std::endl;
	ss << "Gold: " << m_gold << std::endl;
	ss << "Current experience: " << m_experience << std::endl;
	ss << "Level: " << m_level << std::endl;
	ss << "Inventory: \n\t";

	for (int i = 0; i < m_inventory.size(); i++)
	{
		ss << m_inventory[i];
		(i == m_inventory.size() - 1) ? ss << "\n" : ss << ", ";
		if ((i + 1) % 5 == 0 && i != m_inventory.size() - 1) ss << "\n\t";
	}

	return ss.str();
};

bool Character::load_save_data(std::string& save_data)
{
	try
	{
		int pos, len;
		pos = save_data.find("Health: ") + 8;
		len = save_data.find("\n", pos) - pos;
		m_health = std::stoi(save_data.substr(pos, len));

		pos = save_data.find("Attack: ") + 8;
		len = save_data.find("\n", pos) - pos;
		m_attack_rating = std::stoi(save_data.substr(pos, len));

		pos = save_data.find("Defense: ") + 8;
		len = save_data.find("\n", pos) - pos;
		m_defense_rating = std::stoi(save_data.substr(pos, len));

		pos = save_data.find("Damage: ") + 8;
		len = save_data.find("\n", pos) - pos;
		m_attack_power = std::stoi(save_data.substr(pos, len));

		pos = save_data.find("Gold: ") + 6;
		len = save_data.find("\n", pos) - pos;
		m_gold = std::stoi(save_data.substr(pos, len));

		pos = save_data.find("Current experience: ") + 20;
		len = save_data.find("\n", pos) - pos;
		m_experience = std::stoi(save_data.substr(pos, len));

		pos = save_data.find("Level: ") + 7;
		len = save_data.find("\n", pos) - pos;
		m_level = std::stoi(save_data.substr(pos, len));

		m_inventory.clear();
		pos = save_data.find("Inventory: \n\t") + 13;
		int ogPos = pos;

		//len = save_data.find(',', pos);
		len = 0;
		while (len != std::string::npos && pos >= ogPos)
		{
			len = save_data.find(',', pos);
			(len == std::string::npos) ? len = save_data.find('\n', pos) - pos : len -= pos;

			m_inventory.push_back(save_data.substr(pos, len));

			pos = save_data.find(',', pos + len) + 2;
			pos += save_data[pos] == '\n' ? 1 : 0;
		}
	}
	catch (std::exception e)
	{
		return false;
	}

	return true;
}

void Character::display_inventory()
{
	 for (int i = 0; i < m_inventory.size(); i++)
		std::cout << m_inventory[i] << "\n";
}

Character::Character()
{
	m_name = " ";
	m_health = 100;
	m_attack_rating = 10;
	m_defense_rating = 10;
	m_attack_power = 50;
	m_gold = 100;
	m_experience = 101;
	m_level = 1;
	m_is_hit = false;
	m_inventory.reserve(10);
}
