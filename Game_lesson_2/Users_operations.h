#pragma once
#include"Date.h"

User addUser(User* users, int& length, User user) {
	User* tmp = new User[length + 1];
	for (size_t i = 0; i < length; i++)
	{
		tmp[i] = users[i];
	}
	tmp[length] = user;
	delete[] users;
	length++;
	return tmp;
}

bool checkUser(User* users, int length, const char login[]) {

	for (size_t i = 0; i < length; i++)
	{
		if (strcmp(users[i].username, login) == 0) return true;
	}

	return false;
}