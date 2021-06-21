#include"user.h"
#include"Source.h"

user::user(const string& N, const Date& D, const string& E, const string& P) :name{ N }, DOB{ D }, email{ E }, ph_num{ P },curr_trip{nullptr}
{}

void user::print()const
{
	cout << name << endl;
	cout << DOB << endl;
	cout << email << endl;
	cout << ph_num << endl;
	cout << "Total Trips: " << Trips.size() << endl;
}

void user::change_name(const string& N)
{
	name = N;
}
void user::change_DOB(const Date& D)
{
	DOB = D;
}
void user::change_ph(const string& P)
{
	ph_num = P;
}
void user::comp_curr_trip()
{
	curr_trip = nullptr;
}

void user::printTrips()
{
	for (int i = 0; i < (int)Trips.size(); i++)
		cout << *Trips[i] << endl;
}

void user::trip_des(trip* T)
{
	for (int i = 0; i < (int)Trips.size(); i++)
	{
		if (Trips[i] == T)
			Trips.erase(Trips.begin() + i);
	}
}

ostream& operator<<(ostream& out, user& U)
{
	U.printu();
	return out;
}

user::~user()
{
	user_des(this);
}

void user::pickARide(trip*&)
{
	cout << "This action can not be performed\n";
}
void user:: ratePassanger(trip*&, int)
{
	cout << "This action can not be performed\n";
}

void user::endARide()
{
	cout << "This action can not be performed\n";
}

trip* user::bookRide(const string&, const string&)
{
	cout << "Could not perform desired operation\n";
	return nullptr;
}
void user::rateDriver(trip*&, int)
{
	cout << "Could not perform desired operation\n";
}
void user::cancelRide()
{
	cout << "Could not perform desired operation\n";
}