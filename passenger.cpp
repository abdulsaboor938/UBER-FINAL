#include"Passenger.h"

Passenger::Passenger(const string& N, const Date& D, const string& E, const string& P, const Payment& PY) :User(N, D, E, P), method{ PY },P_status{false}
{}

ostream& operator<<(ostream& out, const Passenger& D)
{
	D.print();
	cout << D.method;
	if (D.P_status)
		cout << "Currently Riding" << endl;
	else
		cout << "Currently not Riding" << endl;
	return out;
}