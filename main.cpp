#include "console_window.h"
#include "player_list.h"
#include "game.h"
#include "iostream"

int main()
{
	console_window window;
	window.set_window_size();
	window.set_intro();

	char confirm;
	do {

		game game;
		game.play_game();

		/*player_list player;
		player.set_player_list();
		player.get_player_names();*/

		
		/*std::cout <<player.get_player_names()[0]<<" ma wynik xyz " << std::endl;
		std::cout <<player.get_player_names()[1] << " ma wynik zxy " << std::endl;*/

		std::cout << "\nIf you want to play again press [y], if you want to exit game press [n]' \n";
		std::cin >> confirm;


	} while (confirm == 'y' || confirm == 'Y');

	return 0;
}
