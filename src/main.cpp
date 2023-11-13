#include "my_password.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>

using namespace std;

int num;
password a[110];

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
	if(!num) import(num, a);

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
		list(num, a);
		break;
	case 2:
		add(num, a);
		break;
	case 3:
		change(num, a);
		break;
	case 4:
		remove(num, a);
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

	outFile << num << endl;

	for (int i = 1; i <= num; i++)
	{
		a[i].encrypt();

		outFile << a[i].platform << ' ';
		outFile << a[i].userName << ' ';
		outFile << a[i].password << ' ';
		outFile << a[i].key << endl;
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