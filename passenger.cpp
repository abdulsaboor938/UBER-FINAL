#include"passenger.h"

passenger::passenger(const string& N, const Date& D, const string& E, const string& P, const Payment& PY) :user(N, D, E, P), method{ PY },P_status{false}
{}

ostream& operator<<(ostream& out, const passenger& D)
{
	D.print();
	cout << D.method;
	if (D.P_status)
		cout << "Currently Riding" << endl;
	else
		cout << "Currently not Riding" << endl;
	return out;
}