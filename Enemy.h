#pragma once
#include <iostream>

struct Enemy
{
	// Enemy variables
	std::string  m_name;
	bool		 m_is_hit  = false;
	bool		 m_is_dead = false;
	int			 m_health;
	unsigned int m_attack_rating;
	unsigned int m_defense_rating;
	unsigned int m_attack_power;
	unsigned int m_gold;
	unsigned int m_level;

	Enemy(std::string name, int health, unsigned int ar, 
		  unsigned int dr, unsigned int damage, unsigned gold, unsigned level);
	~Enemy();
	void display_stats();
	void drop_loot();
	void take_damage(int damage);
};
