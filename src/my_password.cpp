#include "my_password.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>

using namespace std;

void password::encrypt()
{
	srand(time(0));
	key = rand() % 25 + 1;

	for (int i = 0; i < platform.size(); i++)
	{
		platform[i] -= key;
	}
	for (int i = 0; i < userName.size(); i++)
	{
		userName[i] -= key;
	}
	for (int i = 0; i < password.size(); i++)
	{
		password[i] -= key;
	}
}

void password::decrypt()
{
	for (int i = 0; i < platform.size(); i++)
	{
		platform[i] += key;
	}
	for (int i = 0; i < userName.size(); i++)
	{
		userName[i] += key;
	}
	for (int i = 0; i < password.size(); i++)
	{
		password[i] += key;
	}
}

void passwordImport(int &numberOfPasswords, password passwordArray[])
{
	ifstream inFile;
	inFile.open("password.asad");

	inFile >> numberOfPasswords;

	for (int i = 1; i <= numberOfPasswords; i++)
	{
		inFile >> passwordArray[i].platform;
		inFile >> passwordArray[i].userName;
		inFile >> passwordArray[i].password;
		inFile >> passwordArray[i].key;

		passwordArray[i].decrypt();
	}

	inFile.close();
}

void passwordList(int &numberOfPasswords, password passwordArray[])
{
	system("cls");

	for (int i = 1; i <= numberOfPasswords; i++)
	{
		cout << i << ": ";
		cout << passwordArray[i].platform << ' ';
		cout << passwordArray[i].userName << ' ';
		cout << passwordArray[i].password << endl;
	}
}

void passwordAdd(int &numberOfPasswords, password passwordArray[])
{
	system("cls");

	cout << "Please enter the number of new passwords: ";

	int number;
	cin >> number;

	cout << "Please enter the platform, username and password in sequence:\n";

	for (int i = 1; i <= number; i++)
	{
		cout << i << ": ";
		cin >> passwordArray[++numberOfPasswords].platform;
		cin >> passwordArray[numberOfPasswords].userName;
		cin >> passwordArray[numberOfPasswords].password;
	}

	cout << "Added successfully!";
}

void passwordChange(int &numberOfPasswords, password passwordArray[])
{
	system("cls");

	passwordList(numberOfPasswords, passwordArray);

	cout << "Please enter the password number that needs to be changed: ";

	int number;
	cin >> number;

	cout << "Please enter the platform, username and password in sequence:\n";

	cin >> passwordArray[number].platform;
	cin >> passwordArray[number].userName;
	cin >> passwordArray[number].password;

	cout << "Successfully modified!";
}

void passwordRemove(int &numberOfPasswords, password passwordArray[])
{
	system("cls");

	cout << "Please enter the password number that needs to be deleted:\n";

	int number;
	cin >> number;

	for (int i = number; i < numberOfPasswords; i++)
	{
		passwordArray[i] = passwordArray[i + 1];
	}
	numberOfPasswords--;

	cout << "Successfully deleted!";
}

void passwordHome(int &numberOfPasswords, password passwordArray[])
{
	if(!numberOfPasswords) passwordImport(numberOfPasswords, passwordArray);

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
		passwordList(numberOfPasswords, passwordArray);
		break;
	case 2:
		passwordAdd(numberOfPasswords, passwordArray);
		break;
	case 3:
		passwordChange(numberOfPasswords, passwordArray);
		break;
	case 4:
		passwordRemove(numberOfPasswords, passwordArray);
		break;
	default:
		break;
	}

	char operation = _getch();

	if (operation != 'q') passwordHome(numberOfPasswords, passwordArray);
}

void passwordExport(int &numberOfPasswords, password passwordArray[])
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