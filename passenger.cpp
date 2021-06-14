#include"passenger.h"

passenger::passenger(const string& N, const Date& D, const string& E, const string& P, const Payment& PY) :user(N, D, E, P), p1{ PY }, p2{ PY }, p3{ PY }, P_status{ false }, methods{ 1 }
{}

ostream& operator<<(ostream& out, const passenger& D)
{
	D.print();
	if (D.methods == 1)
		cout << D.p1 << endl;
	else if (D.methods == 2)
		cout << D.p2 << endl;
	else if (D.methods == 3)
		cout << D.p3 << endl;
	if (D.P_status)
		cout << "Currently Riding" << endl;
	else
		cout << "Currently not Riding" << endl;
	return out;
}

void passenger::bookride(const string& P, const string& D)
{

}