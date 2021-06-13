#include"trip.h"

trip::trip(const string& T, const string& D, passenger* P) :status{ 0 }, T_date(), Driver{ nullptr }, pick{ T },drop{D}
{
	Passenger = P;
	cout << "Trip constructor called" << endl;
}

void trip::change_staus(const int& x)
{
	status = x;
}

void trip::rate_driver(const double& x)
{
	D_rating = x;
}
void trip::rate_passenger(const double& x)
{
	P_rating = x;
}

void trip::set_pickup(const string& x)
{
	pick = x;
}
void trip::set_dropoff(const string& x)
{
	drop = x;
}
void trip::set_driver(driver* x)
{
	Driver = x;
}