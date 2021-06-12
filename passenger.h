#include"user.h"

#ifndef PASSENGER_H
#define PASSENGER_H
class Passenger :protected User
{
	//payment methods
public:
	Passenger(const string&, const Date&, const string&, const string&);
	friend ostream& operator<<(ostream&, const Passenger&);
};
#endif