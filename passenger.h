#include"user.h"
#include"payment.h"

#ifndef PASSENGER_H
#define PASSENGER_H
class passenger :protected user
{
	bool P_status; // 1 means riding
	payment p1, p2, p3;
	int methods;
public:
	passenger(const string&, const Date&, const string&, const string&,const payment&);
	friend ostream& operator<<(ostream&, const passenger&);
	trip* bookRide(const string&, const string&);
};
#endif