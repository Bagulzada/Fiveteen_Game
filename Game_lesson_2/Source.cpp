#include"Date.h"
#include"Game_logic.h"
#include"UI.h"
#include"file_functions.h"
#include"Users_operations.h"

using namespace std;

void game(ushort game_fieald[][4]) {

}

int main() {
	srand(time(NULL));
	User admin;
	strcpy_s(admin.username, 50, "Admin");
	strcpy_s(admin.password, 50, encrypt("Password"));
	cout << admin.username << endl;
	//startIntro();
	ushort game_field[4][4];
	ushort menuItem = 0;

	const char* introMenu[] = {
		"	Sign In",
		"	Sign Up",
		"	Exit"
	};
	const char* startMenu[] = {
		"	Start game",
		"	Load game",
		"	Exit"
	};

	const char* levelMenu[] = {
		"	Easy",
		"	Medium",
		"	Hard"
	};

	menuItem = menu(introMenu, 3);
	char login[50]{};
	char password[50]{};
	switch (menuItem)
	{
	case 1:
		cout << "Enter your login : ";
		cin >> login;
		cout << "Enter your password : ";
		cin >> password;
		int index = checkUser(users, 1, login);
		if (index != -1
			&& strcmp(encrypt(password, 3), users[index]))
	case 2:
		break;
	case 3:
		return 0;
	}

	menuItem = menu(startMenu, 3);
	switch (menuItem)
	{
	case 1:
		system("cls");
		menuItem = menu(levelMenu, 3);
		break;
	case 2: 
		load(game_field);
		break;
	case 3: return 0;
	}

	system("cls");

	fillFields(game_field);
	startPosition(game_field, menuItem);
	showFields(game_field);

	unsigned char arrow{};


	while (!isWin(game_field))
	{
		arrow = _getch();
		if (arrow == 224) arrow = _getch();

		system("cls");

		movement(game_field, arrow);

		showFields(game_field);
	}

	system("cls");
	for (size_t i = 0; i < 10; i++)
	{
		cout << "You WIN!!";
		Sleep(100);
		Beep(1500, 100); // частота и длительность звука
		system("cls");
		cout << "";
		Beep(1500, 100);
		Sleep(100);
		Beep(1500, 100);
	}
}
