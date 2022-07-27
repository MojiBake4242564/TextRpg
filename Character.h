#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

struct Character
{
	//character variables
	const unsigned int MAX_LEVEL = 100;
	const unsigned int MAX_EXP	 = 1000000;

	std::string  m_name;
	std::vector<std::string> m_inventory = {};
	
	bool		 m_is_hit;
	int			 m_max_health;
	int			 m_health;
	unsigned int m_attack_rating;
	unsigned int m_defense_rating;
	unsigned int m_attack_power;
	unsigned int m_gold;
	unsigned int m_level;
	unsigned int m_experience;
	unsigned int m_exp_to_lvl_up;

	
	//functions
	Character();

    void display_stats();
	void display_inventory();
	void level_up();
	void take_damage(int damage);
	bool load_save_data(std::string& save_data);
	std::string get_save_data();
};
