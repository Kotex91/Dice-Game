#include "player_list.h"
#include <iostream>
#include <vector>
#include <string>


player_list::player_list() : player_names(0, ""), game_results(4, 0) {}

void player_list::set_player_list()
{
    using std::cout;
    using std::string;
    using std::cin;
    using std::endl;

    int number_of_players;


    do {
        cout << "\nEnter the number of players (2-6): ";
        cin >> number_of_players;

        if (cin.fail() || number_of_players < 2 || number_of_players > 6) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nInvalid input. \nPlease enter a valid number of players (2-6).\n" << endl;
            continue;
        }
        cout << endl;

        player_names.resize(number_of_players, ""); // Dynamiczne dostosowanie liczby graczy
        game_results.resize(number_of_players, 0); // Dynamiczne dostosowanie liczby graczy

        for (int i = 0; i < number_of_players; ++i) {
            cout << "Player " << i + 1 << ":\t ";
            cin >> player_names[i];
        }

    } while (number_of_players < 2 || number_of_players > 6);
};


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