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

void import(int &num, password a[])
{
	ifstream inFile;
	inFile.open("password.asad");

	inFile >> num;

	for (int i = 1; i <= num; i++)
	{
		inFile >> a[i].platform;
		inFile >> a[i].userName;
		inFile >> a[i].password;
		inFile >> a[i].key;

		a[i].decrypt();
	}

	inFile.close();
}

void list(int &num, password a[])
{
	system("cls");

	for (int i = 1; i <= num; i++)
	{
		cout << i << ": ";
		cout << a[i].platform << ' ';
		cout << a[i].userName << ' ';
		cout << a[i].password << endl;
	}
}

void add(int &num, password a[])
{
	system("cls");

	cout << "Please enter the number of new passwords: ";

	int number;
	cin >> number;

	cout << "Please enter the platform, username and password in sequence:\n";

	for (int i = 1; i <= number; i++)
	{
		cout << i << ": ";
		cin >> a[++num].platform;
		cin >> a[num].userName;
		cin >> a[num].password;
	}

	cout << "Added successfully!";
}

void change(int &num, password a[])
{
	system("cls");

	list(num, a);

	cout << "Please enter the password number that needs to be changed: ";

	int number;
	cin >> number;

	cout << "Please enter the platform, username and password in sequence:\n";

	cin >> a[number].platform;
	cin >> a[number].userName;
	cin >> a[number].password;

	cout << "Successfully modified!";
}

void remove(int &num, password a[])
{
	system("cls");

	cout << "Please enter the password number that needs to be deleted:\n";

	int number;
	cin >> number;

	for (int i = number; i < num; i++)
	{
		a[i] = a[i + 1];
	}
	num--;

	cout << "Successfully deleted!";
}