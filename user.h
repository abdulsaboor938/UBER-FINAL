/*
File made by Abdul Saboor (20L-1113 / BDS 2A) on 21/6/2021
*/
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

public:
	void change_name(const string&);
	void change_DOB(const Date&);
	void change_ph(const string&);
	void comp_curr_trip();
	void printTrips();
	void trip_des(trip*);
	//copy constructor is not available as one user can not be copied to another

	//driver virtual functions
	virtual void pickARide(trip*&);
	virtual void ratePassanger(trip*&, int);
	virtual void endARide();

	// passenger virtual functions
	virtual trip* bookRide(const string&, const string&);
	virtual void rateDriver(trip*&, int);
	virtual void cancelRide();

	virtual double getAvgRating() = 0;
	friend ostream& operator<<(ostream&, user&);


	~user();
};
#endif