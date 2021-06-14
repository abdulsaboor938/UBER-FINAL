#include<iostream>
#include<string>
#include"date.h"
using namespace std;

class trip;

#ifndef USER_H
#define USER_H
class user
{
protected:
	string name;
	Date DOB;
	string email;
	string ph_num;
	//Trips pointers here
	trip *curr_trip;
	int total_trips;
	user(const string&, const Date&, const string&, const string&);
	void print()const;
	//copy constructors
	//stream overload operators
	//getters and setters
	//average rating

public:
	void change_name(const string&);
	void change_DOB(const Date&);
	void change_ph(const string&);

	friend class trip;
};
#endif