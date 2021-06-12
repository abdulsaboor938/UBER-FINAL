#include<iostream>
#include<string>
#include"date.h"
using namespace std;

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

User::User(const string& N, const Date& D, const string& E, const string& P) :name{ N }, DOB{ D }, email{ E }, ph_num{ P }
{}

void User::print()const
{
	cout << name << endl;
	cout << DOB << endl;
	cout << email << endl;
	cout << ph_num << endl;
}