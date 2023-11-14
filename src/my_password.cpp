#include "my_password.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <algorithm>

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

bool cmp(password a, password b)
{
	return a.platform < b.platform;
}

void import(int &numberOfPasswords, password passwordArray[], bool &sortFlag)
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

	inFile >> sortFlag;

	inFile.close();
}

void passwordSort(int &numberOfPasswords, password passwordArray[])
{
	sort(passwordArray + 1, passwordArray + numberOfPasswords + 1, cmp);
}

void list(int &numberOfPasswords, password passwordArray[], bool &sortFlag)
{
	if (!sortFlag)
	{
		passwordSort(numberOfPasswords, passwordArray);
		sortFlag = true;
	}

	system("cls");

	for (int i = 1; i <= numberOfPasswords; i++)
	{
		cout << i << ": ";
		cout << passwordArray[i].platform << ' ';
		cout << passwordArray[i].userName << ' ';
		cout << passwordArray[i].password << '\n';
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

	sortFlag = false;

	cout << "Added successfully!";
}

void change(int &numberOfPasswords, password passwordArray[], bool &sortFlag)
{
	system("cls");

	list(numberOfPasswords, passwordArray, sortFlag);

	cout << "Please enter the number of passwords you need to modify: ";

	int number;
	cin >> number;

	for (int i = 1; i <= number; i++)
	{
		cout << "Please enter the serial number of the password that needs to be modified: ";

		int serialNumber;
		cin >> serialNumber;

		cout << "Please enter the number in the form you expect to modify the password:\n";
		cout << "1.Change password only\n";
		cout << "2.Change username only\n";
		cout << "3.Modify both of the above\n";
		cout << "4.Modify All\n";

		int operation;
		cin >> operation;
		switch (operation)
		{
		case 1:
			cout << "Please enter the new password: ";
			cin >> passwordArray[serialNumber].password;
			break;
		case 2:
			cout << "Please enter the new username: ";
			cin >> passwordArray[serialNumber].userName;
			break;
		case 3:
			cout << "Please enter the new username: ";
			cin >> passwordArray[serialNumber].userName;
			cout << "Please enter the new password: ";
			cin >> passwordArray[serialNumber].password;
			break;
		case 4:
			cout << "Please enter the new platform: ";
			cin >> passwordArray[serialNumber].platform;
			cout << "Please enter the new username: ";
			cin >> passwordArray[serialNumber].userName;
			cout << "Please enter the new password: ";
			cin >> passwordArray[serialNumber].password;
			sortFlag = false;
			break;
		default:
			break;
		}
	}

	cout << "All passwords have been successfully modified!";
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