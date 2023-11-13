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
void import(int &num, password a[]);
void list(int &num, password a[]);
void add(int &num, password a[]);
void change(int &num, password a[]);
void remove(int &num, password a[]);

#endif