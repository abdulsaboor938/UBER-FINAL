#include<iostream>
#include<string>
using namespace std;

#ifndef PAYMENT_H
#define PAYMENT_H
class payment
{
	const string mode;
	string card_num;

public:
	payment(const string&, const string&);
	payment(const string&);
	friend ostream& operator<<(ostream&, const payment&);
};
#endif