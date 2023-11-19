#include "my_password.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>

using namespace std;

int numberOfPasswords;
password passwordArray[110];

bool sortFlag;

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
	if(!numberOfPasswords) import(numberOfPasswords, passwordArray, sortFlag);

	system("cls");
	cout << "Please enter a number to perform the corresponding operation:\n";
	cout << "1.List Password\n";
	cout << "2.Add Password\n";
	cout << "3.Change Password\n";
	cout << "4.Remove Password\n";
	cout << "5.Go Back\n";

	int number;
	cin >> number;
	switch (number)
	{
	case 1:
		list(numberOfPasswords, passwordArray, sortFlag);
		break;
	case 2:
		add(numberOfPasswords, passwordArray, sortFlag);
		break;
	case 3:
		change(numberOfPasswords, passwordArray, sortFlag);
		break;
	case 4:
		remove(numberOfPasswords, passwordArray, sortFlag);
		break;
	default:
		break;
	}

	char operation = _getch();

	if (operation != 'q') home();
}

int main()
{
	if (!masterPassword()) return 0;

	home();

	Export(numberOfPasswords, passwordArray, sortFlag);
	return 0;
}