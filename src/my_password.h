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

bool cmp(password a, password b);

void Sort(int &numberOfPasswords, password passwordArray[]);

void import(int &numberOfPasswords, password passwordArray[], bool &sortFlag);
void list(int &numberOfPasswords, password passwordArray[], bool &sortFlag);
void add(int &numberOfPasswords, password passwordArray[], bool &sortFlag);
void change(int &numberOfPasswords, password passwordArray[], bool &sortFlag);
void remove(int &numberOfPasswords, password passwordArray[], bool &sortFlag);
void Export(int &numberOfPasswords, password passwordArray[], bool &sortFlag);

#endif