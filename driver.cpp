#include"driver.h"

driver::driver(const string& N, const Date& D, const string& E, const string& P, const string& L, const string& V) :user(N, D, E, P), lic_num{ L }, veh_num{ V },D_status{false}
{}

ostream& operator<<(ostream& out, const driver& D)
{
	D.print();
	cout << D.lic_num << endl;
	cout << D.veh_num << endl;
	if (D.D_status)
		cout << "Currently Driving" << endl;
	else
		cout << "Currently not Driving" << endl;

	return out;
}