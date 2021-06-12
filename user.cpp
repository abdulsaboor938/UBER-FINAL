#include"user.h"

User::User(const string& N, const Date& D, const string& E, const string& P) :name{ N }, DOB{ D }, email{ E }, ph_num{ P },total_trips{0}
{}

void User::print()const
{
	cout << name << endl;
	cout << DOB << endl;
	cout << email << endl;
	cout << ph_num << endl;
	cout << "Total Trips: " << total_trips << endl;
}

void User::change_name(const string& N)
{
	name = N;
}
void User::change_DOB(const Date& D)
{
	DOB = D;
}
void User::change_ph(const string& P)
{
	ph_num = P;
}