#include"user.h"

user::user(const string& N, const Date& D, const string& E, const string& P) :name{ N }, DOB{ D }, email{ E }, ph_num{ P },total_trips{0},curr_trip{nullptr}
{}

void user::print()const
{
	cout << name << endl;
	cout << DOB << endl;
	cout << email << endl;
	cout << ph_num << endl;
	cout << "Total Trips: " << total_trips << endl;
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