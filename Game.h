#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <chrono>
#include <thread>

#include "Test.h"
#include "Enemy.h"
#include "Vendor.h"
#include "Character.h"

struct Game
{
	std::string directory = "D:/TextRpg/TextRpg/TextRpg/saves/";
	int m_choice;
	bool m_playing;

	Character player;
	Game();

	bool load_save_file(Character& player);
	bool create_save_file(Character& player);
	void save_file(Character& player);

	void start_menu();
	void combat_menu();
	void main_menu();
	void vendor_menu();
};
