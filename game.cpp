#include "game.h"
#include "player_list.h"
#include <iomanip>
#include <algorithm>

game::game()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	dice_result = 0;
}

void game::roll_dice()
{
	dice_result = rand() % 6 + 1;
}

void game::play_game()
{
	players.set_player_list();

	int number_of_players = players.get_player_names().size();

	std::cout << std::setfill(' ') << std::setw(70) << "Press Enter to start the game!" << std::endl;
	std::cin.get();

	for (int i = 0; i < number_of_players; ++i) {
		std::cout << "\n" << players.get_player_names()[i] << ", it's your turn to roll the dice. Press Enter to roll...";
		std::cin.get(); // Wait for Enter key
		roll_dice();
		std::cout << "You rolled a " << dice_result << "!\n";
		players.set_game_results(i, dice_result);
	}

	std::cout << "\n";
	std::cout << std::setfill(' ') << std::setw(70) << "Press Enter to to see the reuslt!" << std::endl;
	std::cin.get();


	

	seting_winner(); 
};


void game::seting_winner()
{

	std::cout << "\nFinal Results:\n";
	const std::vector<int>& results = players.get_game_results();

	int max_result = -1;
	int winning_player_index = -1;

	for (int i = 0; i < results.size(); ++i) {
		std::cout << players.get_player_names()[i] << ":\t " << results[i] << "\n";

		if (results[i] > max_result) {
			max_result = results[i];
			winning_player_index = i;
		}
	}

	int count_winners = 0;
	for (int i = 0; i < results.size(); ++i) {
		if (results[i] == max_result) {
			++count_winners;
		}
	}

	if (count_winners == 1) {
		std::cout << "\n" << players.get_player_names()[winning_player_index] << " wins with the highest score of " << max_result << "!\n";
	}
	else {
		std::cout << "\nIt's a tie! Multiple players have the highest score of " << max_result << "!\n";
	}
	std::cout << "\n";
	std::cout << std::setfill('*') << std::setw(120) << "*" << std::endl;
}

