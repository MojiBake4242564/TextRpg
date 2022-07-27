#include "Enemy.h"

Enemy::Enemy(std::string name, int health, unsigned int ar,
	unsigned int dr, unsigned int damage, unsigned gold, unsigned level)
{
	m_name = name;
	m_health = health;
	m_attack_rating = ar;
	m_defense_rating = dr;
	m_attack_power = damage;
	m_gold = gold;
	m_level = level;
}

Enemy::~Enemy()
{
}

void Enemy::display_stats()
{
	std::cout << "Enemy Name: " << m_name << std::endl;
	std::cout << "Enemy Health: " << m_health << std::endl;
	std::cout << "Enemy Chance to hit: " << m_attack_rating << std::endl;
	std::cout << "Enemy Chance to evade: " << m_defense_rating << std::endl;
	std::cout << "Enemy Damage: " << m_attack_power << std::endl;
	std::cout << "Enemy Gold: " << m_gold << std::endl;
	std::cout << "Enemy Level: " << m_level << std::endl;
	std::cout << std::endl;
}

void Enemy::take_damage(int damage)
{
	if (m_health > 0)
		m_health -= damage;
}

void Enemy::drop_loot()
{

}