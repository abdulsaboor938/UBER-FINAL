#include<iostream>
#include<string>
using namespace std;
class driver;
class passenger;
#include"date.h"

class Trip
{
	int status;
	driver* Driver;
	passenger* Passenger;
	Date T_date;
	string pick;
	string drop;
	double D_rating;
	double P_rating;

public:
	void change_staus(int);
	void rate_driver(const double&);
	void rate_passenger(const double&);
	void set_pickup(const string&);
	void set_dropoff(const string&);
	void set_driver(const driver*&);
	void set_passenger(const passenger*&);
};