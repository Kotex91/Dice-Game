#include "console_window.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>

console_window::console_window() {}

void console_window::set_intro()
{
	HWND console = GetConsoleWindow();		
	SetConsoleTitle(L"Dice Game!");				

	using std::cout;
	using std::endl;
	using std::setw;
	using std::setfill;

	cout << setfill('*') << setw(120) << "*" << endl;				 
	cout << setfill(' ') << std::setw(60) << "DICE GAME!" << endl;	 					
	cout << setfill('*') << setw(120) << "*" << endl;
	cout << "\nRules:" << endl;
	cout << "\t-Minimum number of players - 2" << endl;
	cout << "\t-Maximum number of players - 6" << endl;
	cout << "\t-Each player rolls the die once" << endl;
	cout << "\t-The player with the highest score wins" << endl;
	cout << "\nGood luck and have fun!\n" << endl;
	cout << setfill('*') << setw(120) << "*" << endl;
}