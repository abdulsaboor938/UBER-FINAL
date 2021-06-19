#include"trip.h"

trip::trip(const string& T, const string& D, passenger* P,const string& N) :status{ 0 }, T_date(), Driver{ nullptr }, pick{ T },drop{D},D_rating{0},P_rating{0},p_name{N}
{
	Passenger = P;
	cout << "Trip constructor called" << endl;
}

trip trip::operator=(trip& T)
{
	cout << "trip copy constructor called" << endl;
	return *this;
}

void trip::change_status(const int& x)
{
	status = x;
}

void trip::rate_driver(const int& x)
{
	D_rating = x;
}
void trip::rate_passenger(const int& x)
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
void trip::set_driver(driver* x,const string& N)
{
	Driver = x;
	d_name = N;
}

passenger* trip::get_passenger_ptr()
{
	return this->Passenger;
}


string trip::get_pickup()
{
	return pick;
}
string trip::get_dropoff()
{
	return drop;
}
int trip:: get_status()
{
	return status;
}
trip* trip::get_ptr()
{
	return this;
}

ostream& operator<<(ostream& out, const trip& T)
{
	out << "Trip Status: ";
	if (T.status == 0)
		out << "Looking for Driver" << endl;
	else if (T.status == 1)
		out << "Trip in progress" << endl;
	else if (T.status == 2)
		out << "Trip completed" << endl;
	else
		out << "Trip cancelled" << endl;
	out <<"Date: "<< T.T_date << endl;
	out << "Pick up location: " << T.pick << endl;
	out << "Drop off location: " << T.drop << endl;
	out << "Passenger name: " << T.p_name << endl;
	if (T.Driver)
		out << "Driver name: " << T.d_name << endl;
	out << "Passenger's rating: " << T.P_rating << endl;
	out << "Driver's rating: " << T.D_rating << endl;

	return out;
}