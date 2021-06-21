/*
File made by Abdul Saboor (20L-1113 / BDS 2A) on 21/6/2021
*/
#include"trip.h"
#include"driver.h"
#include"passenger.h"

trip::trip(const string& T, const string& D, passenger* P) :status{ 0 }, T_date(), Driver{ nullptr }, pick{ T },drop{D},D_rating{0},P_rating{0}
{
	Passenger = P;
	cout<<P->getName() << " books a ride\n";
}

trip trip::operator=(trip& T)
{
	cout << "trip copy constructor called" << endl;
	return *this;
}

void trip::change_status(const int& x)
{
	status = x;
	if (status == 1)
		cout << Driver->getName() << " picks " << Passenger->getName() << "'s ride\n";
	else if (status == 2)
		cout << Driver->getName() << " completes the ride\n";
	else if (status == 3)
		cout << Passenger->getName() << " cancels the ride\n";
}

void trip::rate_driver(const int& x)
{
	D_rating = x;
	cout << Passenger->getName() << " rates " << Driver->getName() << " " << x << "\n";
}
void trip::rate_passenger(const int& x)
{
	P_rating = x;
	cout << Driver->getName() << " rates " << Passenger->getName() << " " << x << "\n";

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
	out << "Passenger name: " << T.Passenger->getName() << endl;
	if (T.Driver)
		out << "Driver name: " << T.Driver->getName() << endl;
	if (T.status == 2) {
		out << "Passenger's rating: " << T.P_rating << endl;
		out << "Driver's rating: " << T.D_rating << endl;
	}

	return out;
}

void trip::trip_comp()
{
	if(Passenger)
		Passenger->R_comp();
	if(Driver)
		Driver->R_comp();
}

int trip::get_Prating()
{
	return P_rating;
}
int trip::get_Drating()
{
	return D_rating;
}

void trip::rem_D()
{
	Driver = nullptr;
}
void trip::rem_P()
{
	Passenger = nullptr;
}

trip::~trip()
{
	if(Passenger!=nullptr)
		Passenger->trip_des(this);
	if(Driver!=nullptr)
		Driver->trip_des(this);
}