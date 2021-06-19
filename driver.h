#include"user.h"
#include "passenger.h"

#ifndef DRIVER_H
#define DRIVER_H
class driver :protected user
{
	string lic_num;
	string veh_num;
public:
	driver(const string&, const Date&, const string&, const string&, const string&, const string&);
	friend ostream& operator<<(ostream&, const driver&);
	void pickARide(trip*&);
	void ratePassanger(trip*&, int);
	void endARide();
	string getName();

};
#endif