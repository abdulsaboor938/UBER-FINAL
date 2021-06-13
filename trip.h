#include<iostream>
#include<string>
using namespace std;
class driver;
class passenger;
#include"date.h"

#ifndef TRIP_H
#define Trip_h
class trip
{
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
	double D_rating;
	double P_rating;

public:
	trip(const string&,const string&,passenger*);
	void change_staus(const int&);
	void rate_driver(const double&);
	void rate_passenger(const double&);
	void set_pickup(const string&);
	void set_dropoff(const string&);
	void set_driver(driver*);
};
#endif