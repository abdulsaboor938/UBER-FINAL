#include<iostream>
#include<vector>
using namespace std;

#include"date.h"
//#include"user.h"
#include"driver.h"
#include"passenger.h"
#include"payment.h"
#include"trip.h"


vector<trip*> uberTrips;
vector<user*> allUsers;

int n = 0;
void addToUberTrips(trip* t)// function to add new trips to uberTrips
{
	if(t!=nullptr)
	{
		uberTrips.push_back(t);
		n++;
	}
} 
void printUberTrips() //function to print uberTrips
{
	for(int i=0; i<(int)uberTrips.size(); i++)
	{
		cout<<i<<" "<<*uberTrips[i]<<endl;
	}
} 

void addToAllUsers(user* U)// function to add new trips to uberTrips
{
	if (U != nullptr)
	{
		allUsers.push_back(U);
	}
}

void printAllUsers()
{
	for (int i = 0; i < (int)allUsers.size(); i++)
	{
		cout << "User " << i + 1 << ": " << endl;
		allUsers[i]->printu();
		cout << "----------------------------------------------\n\n";
	}
}

int main()
{

	driver *d1= new driver("D1", Date(16,1,1990), "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917");
	passenger* p1 = new passenger("P1", Date(10, 10, 1990), "ali@yahoo.com", "0334564334", payment("111-222-333-333", "card"));
	printAllUsers();
	/*
	//////Test Case 1, user books, driver picks, driver ends (rating can be given only in this case)
	//cout<<*p1<<endl;
	//cout<<*d1<<endl; 

	addToUberTrips( p1->bookRide("A", "B"));// will create a new trip and add it to uberTrips array

	cout<<*uberTrips[n-1];// will print this trip
	addToUberTrips( p1->bookRide("C", "D"));//prints error as p1 has already booked a ride
	cout << endl;
	d1->pickARide(uberTrips[n-1]); //will assign  d1 to uberTrip[0], the status of this ride will also change to InProgress
	cout << *uberTrips[n - 1];// will print this trip
	d1->ratePassanger(uberTrips[n-1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n-1],4); //error as the trip is not complete

	cout<<*p1<<endl;
	cout<<*d1<<endl; 
	
	d1->endARide(); //will change the status of uberTrip[0] to Complete

	d1->ratePassanger(uberTrips[n-1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n-1],4); //error as the trip is not complete
	cout<<*uberTrips[n-1]<<endl;
	cout<<*p1<<endl;
	cout<<*d1<<endl; 
	d1->pickARide(uberTrips[n-1]);//prints error as the ride is completed
	cout<<"-------------------------------------"<<endl;
	
	//////Test case 2: user books, driver picks, user cancels, ratings are not applicable to cancelled ride
	addToUberTrips(p1->bookRide("C", "D"));
	d1->pickARide(uberTrips[n-1]); 
	cout<<*p1<<endl;
	cout<<*d1<<endl;
	p1->cancelRide();
	p1->cancelRide();//error as there is no current ride
	cout<<*p1<<endl;
	cout<<*d1<<endl;
	d1->ratePassanger(uberTrips[n-1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n-1], 5); //error as the ride was not complete
	cout<<"-------------------------------------"<<endl;
	
	////Test Case 3: user Books, user Cancels, driver cannot pick this ride now, ratings are not applicable to this ride
	addToUberTrips(p1->bookRide("D", "E"));
	p1->cancelRide();
	d1->pickARide(uberTrips[n-1]); //error as this ride is not looking for driver
	d1->ratePassanger(uberTrips[n-1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n-1], 5); //error as the ride was not complete
	cout<<"-------------------------------------"<<endl;
	
	////Test Case 4: getting avg ratings adn print trip funnction
	//Adding some more test data
	addToUberTrips( p1->bookRide("X", "Y"));
	d1->pickARide(uberTrips[n-1]); 
	d1->endARide(); 
	d1->ratePassanger(uberTrips[n-1], 3); 
	p1->rateDriver(uberTrips[n-1],5); 

	addToUberTrips( p1->bookRide("X", "Y"));
	d1->pickARide(uberTrips[n-1]); 
	d1->endARide(); 
	d1->ratePassanger(uberTrips[n-1], 6);//error as the rating is not between 1 and 5 
	d1->ratePassanger(uberTrips[n-1], 4);
	d1->ratePassanger(uberTrips[n-1], 3);// will upate the passanging rating from 4 to 3
	p1->rateDriver(uberTrips[n-1],1);

	system("cls");
	p1->printTrips();
	cout << "\n----------------------------\n\n";
	d1->printTrips();
	cout << p1->getAvgRating() << endl;
	cout << d1->getAvgRating() << endl;
	
	delete d1;
	delete p1;*/
	

	system("PAUSE");
	return 0;
}