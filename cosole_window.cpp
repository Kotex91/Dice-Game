#include "console_window.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>

console_window::console_window() {}

void console_window::set_window_size()
{
	// Uzyskanie uchwytu do okna konsoli
	HWND console = GetConsoleWindow();

	// Ustawienie tytu³u okna konsoli
	SetConsoleTitle(L"Dice Game!");

	// Ustawienie rozmiaru konsoli
	SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = 30;  // Wysokoœæ konsoli
	rect.Right = 120;   // Szerokoœæ konsoli

	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);

	// Ustawienie bufora konsoli
	COORD bufferSize;
	bufferSize.X = 120;  // Szerokoœæ bufora
	bufferSize.Y = 120;  // Wysokoœæ bufora

	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);

	
}

void console_window::set_intro()
{
	using std::cout;
	using std::endl;
	using std::setw;
	using std::setfill;

	cout << setfill('*') << setw(120) << "*" << endl;
	cout << setfill(' ') << std::setw(60) << "DICE GAME!" << endl;
	cout << setfill('*') << setw(120) << "*" << endl;
	cout << "\nRules:" << endl;
	cout << "\t-This game can be played by two to four players" << endl;
	cout << "\t-Each player rolls the die " << endl;
	cout << "\t-The player with the highest score wins" << endl;
	cout << "\nGood luck and have fun!\n" << endl;
	cout << setfill('*') << setw(120) << "*" << endl;
}