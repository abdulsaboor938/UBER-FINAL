#include"driver.h"
#include"Source.h"

driver::driver(const string& N, const Date& D, const string& E, const string& P, const string& L, const string& V) :user(N, D, E, P), lic_num{ L }, veh_num{ V }
{
	addToAllUsers(this); // to automatically add newly created user to allUsers array
}

void driver::pickARide(trip*& T)
{
	if (T->get_status() != 0) {
		cout << "This ride is not looking for a Driver" << endl;
		return;
	}
	else
	{
		Trips.push_back(T);
		T->set_driver(this, this->name);
		T->change_status(1);
		curr_trip = T;
	}
}
void driver::ratePassanger(trip*& T, int R)
{
	if (T->get_status() != 2||R<0||R>5)
	{
		cout << "\nError in Rating\n" << endl;
		return;
	}
	else
	{
		T->rate_passenger(R);
		return;
	}
}
string driver::getName()
{
	return name;
}
void driver::endARide()
{
	if (curr_trip)
	{
		curr_trip->change_status(2);
		curr_trip->trip_comp();
	}
	else
	{
		cout << "\nError in completing this ride\n\n";
	}
}
void driver::R_comp()
{
	curr_trip = nullptr;
}
double driver::getAvgRating()
{
	double rating = 0;
	int rating_count = 0;
	for (int i = 0; i < (int)Trips.size(); i++)
	{
		if (Trips[i]->get_status() == 2) {
			rating += Trips[i]->get_Drating();
			rating_count++;
		}
	}
	rating /= rating_count;
	return rating;
}
void driver::printu()
{
	cout << *this;
}

driver::~driver()
{
	for (int i = 0; i < (int)Trips.size(); i++)
	{
		Trips[i]->rem_D();
		Trips[i] = nullptr;
	}
}

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