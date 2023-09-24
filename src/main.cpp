#include "my_password.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>

using namespace std;

int numberOfPasswords;
password passwordArray[110];

bool masterPassword()
{
	string masterPassword = "I am Asad.";

	char partOfPassword;
	for (int i = 0; i < masterPassword.size(); i++)
	{
		partOfPassword = _getch();
		if (partOfPassword != masterPassword[i]) return false;
	}
	return true;
}

void home()
{
	system("cls");

	cout << "Please enter a number to perform the corresponding operation:\n";
	cout << "1.Password\n";
	cout << "2.Go Back\n";
	
	int number;
	cin >> number;
	switch (number)
	{
	case 1:
		passwordHome(numberOfPasswords, passwordArray);
		break;
	default:
		break;
	}

	char operation = _getch();

	if (operation != 'q') home();
}

void Export()
{
	passwordExport(numberOfPasswords, passwordArray);
}

int main()
{
	if (!masterPassword()) return 0;

	home();

	Export();
	return 0;
}