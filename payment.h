/*
File made by Abdul Saboor (20L-1113 / BDS 2A) on 21/6/2021
*/
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