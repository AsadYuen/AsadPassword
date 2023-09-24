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

void passwordImport(int &numberOfPasswords, password passwordArray[]);
void passwordList(int &numberOfPasswords, password passwordArray[]);
void passwordAdd(int &numberOfPasswords, password passwordArray[]);
void passwordChange(int &numberOfPasswords, password passwordArray[]);
void passwordRemove(int &numberOfPasswords, password passwordArray[]);
void passwordHome(int &numberOfPasswords, password passwordArray[]);
void passwordExport(int &numberOfPasswords, password passwordArray[]);

#endif