#include"passenger.h"

passenger::passenger(const string& N, const Date& D, const string& E, const string& P, const payment& PY) :user(N, D, E, P), p1{ PY }, p2{ PY }, p3{ PY }, methods{ 1 }
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
	if (D.curr_trip)
		cout << "Currently Riding" << endl;
	else
		cout << "Currently not Riding" << endl;
	return out;
}

trip* passenger::bookRide(const string& P, const string& D)
{
	if (curr_trip != nullptr){
		cout << "\nCan not book two rides at once" << endl;
		return nullptr;
	}
	else {
		trip* temp = new trip(P, D, this, this->name);
		curr_trip = temp;
		Trips.push_back(temp);
		return curr_trip;
	}
}

void passenger::rateDriver(trip*& T, int R)
{
	if (T->get_status() != 2)
	{
		cout << "Error in Rating" << endl;
		return;
	}
	else
	{
		T->rate_driver(R);
		return;
	}
}

void passenger::comp_curr_trip()
{
	curr_trip = nullptr;
}