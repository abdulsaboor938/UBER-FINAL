#include"passenger.h"
#include"Source.h"

passenger::passenger(const string& N, const Date& D, const string& E, const string& P, const payment& PY) :user(N, D, E, P)
{
	p_methods.push_back(PY);
	addToAllUsers(this); // to automatically add newly created user to allUsers array
}

trip* passenger::bookRide(const string& P, const string& D)
{
	if (curr_trip != nullptr){
		cout << "\nCan not book two rides at once" << endl;
		return nullptr;
	}
	else {
		trip* temp = new trip(P, D, this);
		curr_trip = temp;
		Trips.push_back(temp);
		return curr_trip;
	}
}
void passenger::rateDriver(trip*& T, int R)
{
	if (T->get_status() != 2||R<0||R>5)
	{
		cout << "\nError in Rating\n" << endl;
		return;
	}
	else
	{
		T->rate_driver(R);
		return;
	}
}
void passenger::cancelRide()
{
	if (curr_trip)
	{
		curr_trip->change_status(3);
		curr_trip->trip_comp();
	}
	else
	{
		cout << "\nError in cancelling this ride\n\n";
	}
}
string passenger::getName()
{
	return name;
}
void passenger::R_comp()
{
	curr_trip = nullptr;
}
double passenger::getAvgRating()
{
	double rating = 0;
	int rating_count = 0;
	for (int i = 0; i < (int)Trips.size(); i++)
	{
		if (Trips[i]->get_status() == 2) {
			rating += Trips[i]->get_Prating();
			rating_count++;
		}
	}
	rating /= rating_count;
	return rating;
}
void passenger::printTrips()
{
	user::printTrips();
}

passenger::~passenger()
{
	for (int i = 0; i < (int)Trips.size(); i++)
	{
		Trips[i]->rem_P();
		Trips[i] = nullptr;
	}
}

void passenger::printu()
{
	cout << *this;
}

ostream& operator<<(ostream& out, const passenger& D)
{
	D.print();
	for (int i = 0; i < (int)D.p_methods.size(); i++)
	{
		cout << D.p_methods[i] << endl;
	}
	if (D.curr_trip)
		cout << "Currently Riding" << endl;
	else
		cout << "Currently not Riding" << endl;
	return out;
}

void passenger::addPayment(const string& card, const string& mode)
{
	if (p_methods.size() < 3)
	{
		p_methods.push_back(payment(card, mode));
	}
	else
	{
		cout << "Error adding paymnet method\n\n";
	}
}
void passenger::deletePayment()
{
	for (int i = 0; i < (int)p_methods.size(); i++)
	{
		p_methods.clear();
	}
}