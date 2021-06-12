#include"user.h"
#include"payment.h"

#ifndef PASSENGER_H
#define PASSENGER_H
class Passenger :protected User
{
	bool P_status; // 1 means riding
	Payment method;
public:
	Passenger(const string&, const Date&, const string&, const string&,const Payment&);
	friend ostream& operator<<(ostream&, const Passenger&);
};
#endif