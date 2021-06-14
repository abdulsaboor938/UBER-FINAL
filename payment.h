#include<iostream>
#include<string>
using namespace std;

#ifndef PAYMENT_H
#define PAYMENT_H
class Payment
{
	const string mode;
	string card_num;

public:
	Payment(const string&, const string&);
	Payment(const string&);
	friend ostream& operator<<(ostream&, const Payment&);
};
#endif