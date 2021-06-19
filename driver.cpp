#include"driver.h"

driver::driver(const string& N, const Date& D, const string& E, const string& P, const string& L, const string& V) :user(N, D, E, P), lic_num{ L }, veh_num{ V }
{}

ostream& operator<<(ostream& out, const driver& D)
{
	D.print();
	cout << D.lic_num << endl;
	cout << D.veh_num << endl;
	if (D.curr_trip)
		cout << "Currently Driving" << endl;
	else
		cout << "Currently not Driving" << endl;

	return out;
}

void driver::pickARide(trip*& T)
{
	if (T->get_status() != 0) {
		cout << "This ride is not looking for a Driver" << endl;
		return;
	}
	else
	{
		T->set_driver(this, this->name);
		T->change_status(1);
		curr_trip = T->get_ptr();
	}
}

void driver::ratePassanger(trip*& T, int R)
{
	if (T->get_status() != 2)
	{
		cout << "Error in Rating" << endl;
		return;
	}
	else
	{
		T->rate_passenger(R);
		return;
	}
}