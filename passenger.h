/*
File made by Abdul Saboor (20L-1113 / BDS 2A) on 21/6/2021
*/
#include"user.h"
#include<vector>
#include"payment.h"

#ifndef PASSENGER_H
#define PASSENGER_H
class passenger :protected user
{
	vector<payment> p_methods;
public:
	passenger(const string&, const Date&, const string&, const string&,const payment&);

	string getName();
	virtual trip* bookRide(const string&, const string&);
	virtual void rateDriver(trip*&, int);
	virtual void cancelRide();
	void R_comp(); // to mark current trip as nullptr
	virtual double getAvgRating();
	void printu();
	void printTrips();
	void trip_des(trip*);

	void addPayment(const string&, const string&);
	void deletePayment();

	~passenger();

	friend ostream& operator<<(ostream&, const passenger&);
};
#endif