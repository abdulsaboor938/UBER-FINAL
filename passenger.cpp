#include"Passenger.h"

Passenger::Passenger(const string& N, const Date& D, const string& E, const string& P) :User(N, D, E, P)
{}

ostream& operator<<(ostream& out, const Passenger& D)
{
	D.print();
	cout << "Papyment Methods" << endl;
	return out;
}