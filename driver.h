#include"user.h"

#ifndef DRIVER_H
#define DRIVER_H
class driver :protected user
{
	bool D_status; // 1 means driving
	string lic_num;
	string veh_num;
public:
	driver(const string&, const Date&, const string&, const string&, const string&, const string&);
	friend ostream& operator<<(ostream&, const driver&);
};
#endif