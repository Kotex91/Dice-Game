#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "player_list.h"

class game {
private:
	int dice_result;
	player_list players;
	void seting_winner();
	void save_results_to_file(const std::string& filename);
	void read_results_from_file(const std::string& filename);

public:
	game();
	void roll_dice();
	void play_game();
};