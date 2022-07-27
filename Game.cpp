#include "Game.h"

Game::Game()
{
	m_choice = 0;
	m_playing = true;

}

void Game::start_menu()
{
	print_number();
	std::cout << "Press 1 for: New game" << std::endl;
	std::cout << "Press 2 for: Load game" << std::endl;
	std::cout << "Press 3 for: Quit" << std::endl;
	
	std::cin >> m_choice;

	switch (m_choice)
	{
		case 1:
			std::cout << "Please enter the name of the character create: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, player.m_name);
			std::cout << std::endl;
			create_save_file(player);
			main_menu();
			break;

		case 2:
			std::cout << "Please enter the name of the character you'd like to load: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, player.m_name);
			std::cout << std::endl;
			load_save_file(player);
			main_menu();
			break;

		case 3:
			std::cout << "Goodbye" << std::endl;
			m_playing = false;
			break;
	}
}

void Game::main_menu()
{
	do
	{
		std::cout << "(1)Fight: " << std::endl;
		std::cout << "(2)Display stats: " << std::endl;
		std::cout << "(3)Display inventory: " << std::endl;
		std::cout << "(4)Shop: " << std::endl;
		std::cout << "(5)Save Game: " << std::endl;
		std::cout << "(6)Exit: " << std::endl;

		std::cin >> m_choice;
		std::cout << std::endl;

		switch (m_choice)
		{
			case 1:
			{
				std::cout << "Entering combat" << std::endl;
				combat_menu();
				std::cout << std::endl;
				break;
			}	
			case 2:
				player.display_stats();
				std::cout << std::endl;
				break;

			case 3:
				player.display_inventory();
				std::cout << std::endl;
				break;

			case 4:
				vendor_menu();
				std::cout << std::endl;
				break;

			case 5:
				//create_save_file(player);
				save_file(player);
				std::cout << std::endl;
				break;

			case 6:
				m_playing = false;
				exit(-1);
				break;
		}
	} while (m_choice != 6);
}

void Game::combat_menu()
{
	Enemy enemy = Enemy("bob", 420, 10, 10, 100, 10, 5);

	do
	{
		std::cout << "Do you want to attack? :" << std::endl;
		std::cin >> m_choice;
		bool is_players_turn = true;

		switch (m_choice)
		{
			case 1:
				enemy.take_damage(player.m_attack_power);
				std::cout << "Enemy took " << player.m_attack_power << " damage \n";
				std::cout << "Enemy hp " << enemy.m_health << "\n";

				if (enemy.m_health <= 0)
					std::cout << "Enemy is dead" << std::endl;

				is_players_turn = false;
				break;

			case 2:
				std::cout << "You do nothing" << std::endl;
				is_players_turn = false;
				break;

		}
		// Enemy's turn
		while (!is_players_turn && enemy.m_health > 0)
		{
			std::cout << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "Enemy is attacking: " << std::endl;
			player.take_damage(enemy.m_attack_power);
			std::cout << "Player took " << enemy.m_attack_power << " damage \n";
			std::cout << "Player hp " << player.m_health << "\n";
			is_players_turn = true;
		}

	} while (enemy.m_health > 0);
}

void Game::vendor_menu()
{
	Vendor vendor;
	vendor.m_name = "Charsi";

	do
	{
		std::cout << "Hello, my name is " << vendor.m_name << " the best blacksmith in town,\n"
					"I also sell all sorts of trinkets and potions!\n"
					"Please have a look at my wares! \n";
		std::cout << std::endl;

		std::cout << "(1) Buy items:\n"
					 "(2) Sell items : \n"
					 "(3) Disply my inventory : \n" 
					 "(0) exit shop : " << std::endl;

		std::cin >> m_choice;

		switch(m_choice)
		{
		case 1:
			vendor.buy_item(player);
			std::cout << std::endl;
			break;
		case 2:
			vendor.sell_item();
			std::cout << std::endl;
			break;
		case 3:
			vendor.display_inventory();
			std::cout << std::endl;
			break;
		case 0:
			std::cout << "Thanks for your patranige!" << std::endl;
			std::cout << std::endl;
			break;
		}
	} while (m_choice != 0);
}

bool Game::load_save_file(Character& player)
{
	std::fstream save_file;

	save_file.open(directory + player.m_name + ".txt");

	if (!save_file.is_open())
	{
		std::cout << "That character does not exist." << std::endl << std::endl;
		return false;
	}
	else
	{
		std::string save_fileData;
		std::string line;

		while (std::getline(save_file, line))
		{
			save_fileData.append(line + '\n');
		}
		
		bool loadSuccess = player.load_save_data(save_fileData);
		if (loadSuccess)
		{
			std::cout << "You have loaded the following character:" << std::endl;
			std::cout << "Name: " << player.m_name << std::endl;
			std::cout << player.get_save_data() << std::endl;
			return true;
		}
		else
		{
			std::cout << "Could not load the character. Corrupted save data." << std::endl;
			return false;
		}
	}
	save_file.close();
}

bool Game::create_save_file(Character& player)
{
	std::fstream save_file;
	save_file.open(directory + player.m_name + ".txt");

	if (save_file.is_open())
	{
		save_file.close();
		std::cout << "That character already exists." << std::endl << std::endl;
		return false;
	}
	else
	{
		save_file.open(directory + player.m_name + ".txt", std::fstream::out);
		save_file << player.get_save_data();
		save_file.close();

		std::cout << "You have created the following character:" << std::endl;
		std::cout << "Name: " << player.m_name << std::endl;
		std::cout << player.get_save_data() << std::endl;
		return true;
	}
}

void Game::save_file(Character& player)
{
	std::fstream save_file;
	//save_file.open(directory + player.m_name + ".txt");

	save_file.open(directory + player.m_name + ".txt", std::fstream::out);
	save_file << player.get_save_data();
	save_file.close();
}
