#include<iostream>
#include<string>
#include"date.h"
using namespace std;

#ifndef USER_H
#define USER_H
class User
{
protected:
	string name;
	Date DOB;
	string email;
	string ph_num;
	//Trips pointers here
public:
	User(const string&, const Date&, const string&, const string&);
	void print()const;
};
#endif