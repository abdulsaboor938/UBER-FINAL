#include<iostream>
#include<string>
using namespace std;
class driver;
class passenger;
#include"date.h"

#ifndef TRIP_H
#define TRIP_H
class trip
{
private:
	int status;
	/*
	0. Looking for Driver
	1. In Progress
	2. Completed
	3. Cancelled
	*/
	driver* Driver;
	passenger* Passenger;
	Date T_date;
	string pick;
	string drop;
	int D_rating;
	int P_rating;

public:
	trip(const string&,const string&,passenger*);
	void change_status(const int&);
	void rate_driver(const int&);
	void rate_passenger(const int&);
	void set_pickup(const string&);
	void set_dropoff(const string&);
	void set_driver(driver*,const string&);

	string get_pickup();
	string get_dropoff();
	int get_status();
	void trip_comp();

	int get_Prating();
	int get_Drating();

	void rem_P();
	void rem_D();

	friend ostream& operator<<(ostream&, const trip&);

	trip operator=(trip&);

	friend class passenger;
	friend class driver;
};
#endif