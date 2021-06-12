#include<iostream>
#include<ctime>
using namespace std;

#ifndef DATE_H
#define DATE_H
class Date
{
	int day;
	int month;
	int year;

public:
	Date();
	Date(int, int, int);
	void set_day(int);
	void set_month(int);
	void set_year(int);

	int get_day()const;
	int get_month()const;
	int get_year()const;

	friend ostream& operator<<(ostream&, const Date&);
};
#endif