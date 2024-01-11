#pragma once

#include <vector>
#include <string>

class player_list
{
public:
	player_list();												//konstruktor
	
	void set_player_list();
	const std::vector<std::string>& get_player_names() const;
	const std::vector<int>& get_game_results() const;
	void set_game_results(int player_index, int result);

private:
	std::vector<std::string> player_names;
	std::vector<int> game_results;
};