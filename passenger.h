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
	trip* bookRide(const string&, const string&);
	void rateDriver(trip*&, int);
	void cancelRide();
	void R_comp(); // to mark current trip as nullptr
	virtual double getAvgRating();
	void printu();
	void printTrips();

	void addPayment(const string&, const string&);
	void deletePayment();

	~passenger();

	friend ostream& operator<<(ostream&, const passenger&);
};
#endif