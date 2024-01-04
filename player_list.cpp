#include "player_list.h"
#include <iostream>
#include <vector>
#include <string>


player_list::player_list() : player_names(0, ""), game_results(0, 0) {}

void player_list::set_player_list()
{
	using std::cout;
	using std::string;
	using std::cin;
	using std::endl;

	int number_of_players;


	do {
		cout << "\nEnter the number of players: ";
		cin >> number_of_players;
		cout << endl;


		switch (number_of_players) {
		case 2:
			cout << "Player one:\t ";
			cin >> player_names[0];
			cout << "Player two:\t ";
			cin >> player_names[1];
			break;

		case 3:
			cout << "Player one:\t ";
			cin >> player_names[0];
			cout << "Player two:\t ";
			cin >> player_names[1];
			cout << "Player three:\t ";
			cin >> player_names[2];
			break;

		case 4:
			cout << "Player one:\t ";
			cin >> player_names[0];
			cout << "Player two:\t ";
			cin >> player_names[1];
			cout << "Player three:\t ";
			cin >> player_names[2];
			cout << "Player four:\t ";
			cin >> player_names[3];
			break;

		default:
			cout << "\nInvalid number of players!" << endl;
			cout << "the number of players must be between 2 and 4!\n" << endl;
			break;
		}
	} while (number_of_players < 2 || number_of_players > 4);


player_names.resize(number_of_players, ""); // Zmienione na dynamiczne dostosowanie liczby graczy

game_results.resize(number_of_players, 0); // Zmienione na dynamiczne dostosowanie liczby graczy
}


const std::vector<std::string>& player_list::get_player_names() const {
	return player_names;
}
const std::vector<int>& player_list::get_game_results() const {
	return game_results;
}

void player_list::set_game_results(int player_index, int result)
{
	if (player_index >= 0 && player_index < 5)
	{
		game_results[player_index] = result;
	}
	else {
		std::cout << "Invalid player index!" << std::endl;
	}
}