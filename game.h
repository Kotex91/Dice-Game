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
	
public:
	game();
	void roll_dice();
	void play_game();
};

   