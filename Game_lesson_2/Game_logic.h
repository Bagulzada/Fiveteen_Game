#pragma once
#include"Date.h"
#include"Helper_functions.h"
#include"file_functions.h"

void fillFields(ushort game_field[][4]) {

	ushort tmp = 1;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			game_field[i][j] = i * 4 + j + 1;
		}
	}
}
void movement(ushort game_field[][4], int side) {

	coord = findEmptyCell(game_field);

	switch (side)
	{
	case 'a':
	case 'A':
	case LEFT:

		if (coord.y + 1 <= 3) {
			swap(game_field[coord.x][coord.y], game_field[coord.x][coord.y + 1]);
		}
		break;
	case 'd':
	case 'D':
	case RIGHT:

		if (coord.y - 1 >= 0) {
			swap(game_field[coord.x][coord.y], game_field[coord.x][coord.y - 1]);
		}
		break;
	case 'w':
	case 'W':
	case UP:

		if (coord.x + 1 <= 3) {
			swap(game_field[coord.x][coord.y], game_field[coord.x + 1][coord.y]);
		}
		break;
	case 's':
	case 'S':
	case DOWN:

		if (coord.x - 1 >= 0) {
			swap(game_field[coord.x][coord.y], game_field[coord.x - 1][coord.y]);
		}
		save(game_field);
		break;
	}
}
void startPosition(ushort game_field[][4], int mode) {

	int turns{};

	switch (mode)
	{
	case EASY:
		turns = 100;
		break;
	case NORMAL:
		turns = 250;
		break;
	case HARD:
		turns = 700;
		break;
	}

	unsigned int random_side{};

	int sides[]{ LEFT, RIGHT, UP, DOWN };

	for (size_t i = 0; i < turns; i++)
	{
		random_side = rand() % 4;
		movement(game_field, sides[random_side]);
	}
}
bool isWin(ushort game_field[][4]) {

	ushort cell_value = 1;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			/*if (cell_value++ != game_field[i][j]) return false;*/
			if (!isRightPosition(game_field, Coord{ ushort(i), ushort(j) })) return false;
		}
	}

	return true;
}