#include<iostream>
#include<string>
#include<vector>
#include"date.h"
using namespace std;

#include"trip.h"

#ifndef USER_H
#define USER_H
class user
{
protected:
	string name;
	Date DOB;
	string email;
	string ph_num;
	vector<trip*> Trips;
	trip *curr_trip;
	user(const string&, const Date&, const string&, const string&);
	void print()const;
	virtual void printu() = 0;
	//copy constructors
	//stream overload operators
	//getters and setters
	//average rating

public:
	void change_name(const string&);
	void change_DOB(const Date&);
	void change_ph(const string&);
	void comp_curr_trip();
	void printTrips();
	void trip_des(trip*);
	//copy constructor is not available as one user can not be copied to another

	virtual double getAvgRating() = 0;
	friend ostream& operator<<(ostream&, user&);


	~user();
};
#endif