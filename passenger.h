#include"user.h"
#include"payment.h"

#ifndef PASSENGER_H
#define PASSENGER_H
class passenger :protected user
{
	bool P_status; // 1 means riding
	Payment method;
public:
	passenger(const string&, const Date&, const string&, const string&,const Payment&);
	friend ostream& operator<<(ostream&, const passenger&);
};
#endif