#include "console_window.h"
#include "player_list.h"
#include "game.h"
#include "iostream"
#include <windows.h>

int main()
{
	console_window window;
	window.set_intro();

	char confirm;
	bool userChoice;

	do {
		game game;
		game.play_game();

		std::cout << "\nIf you want to play again press [Y], if you want to exit game press [N]\n";
		std::cin >> confirm;

	} while (confirm == 'y');

	return 0;
}