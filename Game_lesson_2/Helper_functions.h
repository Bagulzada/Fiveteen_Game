#pragma once
#include "Date.h"

bool isRightPosition(ushort game_field[][4], Coord coord) {
	return game_field[coord.x][coord.y] == coord.x * 4 + coord.y + 1;
}
Coord findEmptyCell(ushort game_field[][4]) {

	for (ushort i = 0; i < 4; i++)
	{
		for (ushort j = 0; j < 4; j++)
		{
			if (game_field[i][j] == 16) {
				return Coord{ i, j };
			}
		}
	}	
}
void encrypt(const char[], char password[]) {



}