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
	if(!numberOfPasswords) import(numberOfPasswords, passwordArray);

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
		list(numberOfPasswords, passwordArray);
		break;
	case 2:
		add(numberOfPasswords, passwordArray);
		break;
	case 3:
		change(numberOfPasswords, passwordArray);
		break;
	case 4:
		remove(numberOfPasswords, passwordArray);
		break;
	default:
		break;
	}

	char operation = _getch();

	if (operation != 'q') home();
}

void Export()
{
	ofstream outFile;
	outFile.open("password.asad");

	outFile << numberOfPasswords << endl;

	for (int i = 1; i <= numberOfPasswords; i++)
	{
		passwordArray[i].encrypt();

		outFile << passwordArray[i].platform << ' ';
		outFile << passwordArray[i].userName << ' ';
		outFile << passwordArray[i].password << ' ';
		outFile << passwordArray[i].key << endl;
	}

	outFile.close();
}

int main()
{
	if (!masterPassword()) return 0;

	home();

	Export();
	return 0;
}