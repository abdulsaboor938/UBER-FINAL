/*
File made by Abdul Saboor (20L-1113 / BDS 2A) on 21/6/2021
*/
#include"user.h"

#ifndef DRIVER_H
#define DRIVER_H
class driver :protected user
{
	string lic_num;
	string veh_num;
public:
	driver(const string&, const Date&, const string&, const string&, const string&, const string&);
	
	virtual void pickARide(trip*&);
	virtual void ratePassanger(trip*&, int);
	virtual void endARide();
	string getName();
	void R_comp(); // ride complete is to null current trip
	virtual double getAvgRating();
	void printu();
	void printTrips();
	void trip_des(trip*);

	~driver();

	friend ostream& operator<<(ostream&, const driver&);
};
#endif