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

void import(int &numberOfPasswords, password passwordArray[])
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

void passwordSort(int &numberOfPasswords, password passwordArray[])
{

}

void list(int &numberOfPasswords, password passwordArray[], bool &sortFlag)
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

void add(int &numberOfPasswords, password passwordArray[], bool &sortFlag)
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

	sortFlag = 0;

	cout << "Added successfully!";
}

void change(int &numberOfPasswords, password passwordArray[], bool &sortFlag)
{
	system("cls");

	list(numberOfPasswords, passwordArray, sortFlag);

	cout << "Please enter the password number that needs to be changed: ";

	int number;
	cin >> number;

	cout << "Please enter the platform, username and password in sequence:\n";

	cin >> passwordArray[number].platform;
	cin >> passwordArray[number].userName;
	cin >> passwordArray[number].password;

	cout << "Successfully modified!";
}

void remove(int &numberOfPasswords, password passwordArray[])
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