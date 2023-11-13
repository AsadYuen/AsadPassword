#ifndef MY_PASSWORD_H
#define MY_PASSWORD_H
#include <string>

class password
{
public:
	std::string platform, userName, password;
	int key;

	void encrypt();
	void decrypt();
};
void import(int &numberOfPasswords, password passwordArray[]);
void list(int &numberOfPasswords, password passwordArray[]);
void add(int &numberOfPasswords, password passwordArray[]);
void change(int &numberOfPasswords, password passwordArray[]);
void remove(int &numberOfPasswords, password passwordArray[]);

#endif