#include"driver.h"

Driver::Driver(const string& N, const Date& D, const string& E, const string& P, const string& L, const string& V) :User(N, D, E, P), lic_num{ L }, veh_num{ V }
{}

ostream& operator<<(ostream& out, const Driver& D)
{
	D.print();
	cout << D.lic_num << endl;
	cout << D.veh_num << endl;
	return out;
}