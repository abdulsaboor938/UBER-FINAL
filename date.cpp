/*
File made by Abdul Saboor (20L-1113 / BDS 2A) on 21/6/2021
*/
#include"date.h"

Date::Date()
{
	time_t now = time(0);

	int t = (int)now;
	year = (t / 31556926) + 1970;
	t %= 31556926;
	month = (t / 2629743) + 1;
	t %= 2629743;
	day = (t / 86400) + 1;
}
Date::Date(int d, int m, int y)
{
	set_day(d);
	set_month(m);
	set_year(y);
}
ostream& operator << (ostream & out, const Date & D)
{
	out << D.day << "/" << D.month << "/" << D.year;
	return out;
}
void Date::set_year(int x)
{
	year = x;
	Date temp;
	int t = temp.get_year();
	while (year < 1900 || year > t)
	{
		cout << "Please Enter a valid year (1990 - " << t << ") : ";
		cin >> year;
	}
}
void Date::set_month(int x)
{
	month = x;
	while (month < 1 || month>12)
	{
		cout << "Please Enter a valid month (1 - 12) : ";
		cin >> month;
	}
}
void Date::set_day(int x)
{
	day = x;
	int max_d = 30;
	if ((year % 4 == 0) && month == 2)
		max_d = 29;
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		max_d = 31;
	while (day<1 || day>max_d)
	{
		cout << "Please Enter a valid day (1 - " << max_d << ") : ";
		cin >> day;
	}
}
int Date::get_day() const
{
	return day;
}
int Date::get_month() const
{
	return month;
}
int Date::get_year() const
{
	return year;
}