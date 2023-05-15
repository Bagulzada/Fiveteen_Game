#pragma once
#include"Date.h"
#include"Helper_functions.h"
#include <iomanip>

void startIntro() {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	const char* intro[]{
	"111 5555555            GGGGGGG     AAAAA       MM      MM      EEEEEEE",
	"111 55                 GG         AA   AA      MMM    MMM      EE     ",
	"111 5555555            GG GGGG    AAAAAAA      M  MMMM  M      EEEEEEE",
	"111      55            GG   GG    AA   AA      M   MM   M      EE     ",
	"111 5555555            GGGGGGG    AA   AA      M        M      EEEEEEE"
	};

	c.X = 20;
	c.Y = 7;
	SetConsoleCursorPosition(h, c);

	for (size_t i = 0; i < 5; i++)
	{
		SetConsoleCursorPosition(h, c);
		++c.Y;
		for (size_t j = 0; j < strlen(intro[i]); j++)
		{
			cout << intro[i][j];
			Sleep(10);
		}
		cout << '\n';
	}
}

void showFields(ushort game_field[][4]) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (game_field[i][j] == 16) {
				SetConsoleTextAttribute(h, 0);
			}
			else if (isRightPosition(game_field, Coord{ ushort(i), ushort(j) })) {
				SetConsoleTextAttribute(h, 10);
			}
			else {
				SetConsoleTextAttribute(h, 4);
			}
			cout << setw(5) << right << game_field[i][j];
		}
		cout << "\n\n";
	}
	SetConsoleTextAttribute(h, 0);
}

ushort menu(const char* Menu[], ushort length) {

	h = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char key{};
	short menuPos = 0;

	while (true)
	{
		menuPos %= 3;
		if (menuPos < 0) menuPos = 2;
		/*if (menuPos == 3) menuPos = 0;
		if (menuPos < 0) menuPos = 2;*/
		for (size_t i = 0; i < 3; i++)
		{
			if (i == menuPos)
				cout << "> " << Menu[i] << endl;
			else {
				cout << " " << Menu[i] << endl;
			}
		}

		key = _getch();
		if (key == 224) {

			key = _getch();
			switch (key)
			{
			case UP:
				menuPos--;
				break;
			case DOWN:
				menuPos++;
				break;
			}
		}
		else {
			if (key == 13) {
				return menuPos + 1;
			}
		}
		system("cls");

	}
}