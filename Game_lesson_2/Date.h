#pragma once
#include<iostream>
#include<conio.h>
#include<time.h>
#include<Windows.h>	

using namespace std;

HANDLE h;

COORD c;

FILE *file;

typedef unsigned short ushort;

enum controllers {
	LEFT = 75,
	RIGHT = 77,
	UP = 72,
	DOWN = 80
};

enum difficulty { 
	EASY = 1,
	NORMAL,
	HARD};

struct Coord {
	ushort x : 3;
	ushort y : 3;
}coord;

struct User {
	char username[50];
	char password[50];
	ushort game_field[4][4];
};
