#include"user.h"

#ifndef DRIVER_H
#define DRIVER_H
class driver :protected user
{
	string lic_num;
	string veh_num;
public:
	driver(const string&, const Date&, const string&, const string&, const string&, const string&);
	
	void pickARide(trip*&);
	void ratePassanger(trip*&, int);
	void endARide();
	string getName();
	void R_comp(); // ride complete is to null current trip
	virtual double getAvgRating();
	void printu();

	~driver();

	friend ostream& operator<<(ostream&, const driver&);
};
#endif