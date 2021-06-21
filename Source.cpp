/*
TODO
	trip destructor & destructors
	do we need to make all functions virtual
	dynamic cast or make a signal inside user to indicate
	general getter setter and copy constructors
	is the way add users implemented correct?
*/

#include<iostream>
#include<vector>
#include<fstream>
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
		cout << *(allUsers[i]);
		cout << "----------------------------------------------\n\n";
	}
}
void read_file(const char* D)
{
	char status;
	string name;
	string email;
	string ph;
	int day, month, year;
	ifstream inFile;
	inFile.open(D, ios::in);
	while (!inFile.eof())
	{
		int dc = 0;
		char arr[100];
		inFile.getline(arr, 100, ',');
		status = arr[0];
		inFile.getline(arr, 100,',');
		name = arr;
		inFile.getline(arr, 100, ',');
		day = (int)arr[dc++]-48;
		if (arr[dc] != '-') {
			day *= 10;
			day += (int)arr[dc++] - 48;
		}
		dc++;
		month = (int)arr[dc++] - 48;
		if (arr[dc] != '-') {
			month *= 10;
			month += (int)arr[dc++] - 48;
		}
		dc++;
		year = (int)arr[dc++] - 48;
		year *= 10;
		year += (int)arr[dc++] - 48;
		year *= 10;
		year += (int)arr[dc++] - 48;
		year *= 10;
		year += (int)arr[dc++] - 48;
		inFile.getline(arr, 100, ',');
		email = arr;
		inFile.getline(arr, 100, '\n');
		ph = arr;
		
		string null = "";
		if (status == 'p')
		{
			passenger* temp=new passenger(name, Date(day, month, year), email, ph, payment(null,null));
		}
		else if (status == 'd')
		{
			driver* temp=new driver(name, Date(day, month, year), email, ph,null,null);

		}

	}
	inFile.close();
}

user* hr_user()
{
	double max=-1, rating;
	int c = 0;
	for (int i = 0; i < (int)allUsers.size(); i++)
	{
		rating = allUsers[i]->getAvgRating();
		if (rating > max)
		{
			max = rating;
			c = i;
		}
	}
	return allUsers[c];
}
user* hr_passenger()
{
	passenger* p;
	double max = 0, rating;
	int c = 0;
	for (int i = 0; i < (int)allUsers.size(); i++)
	{
		rating = allUsers[i]->getAvgRating();
		p = dynamic_cast<passenger*>(allUsers[i]);
		if (p == nullptr && rating > max) // dynamic cast only working on one child and not other that's why it is made equal
		{
			max = rating;
			c = 1;
		}
	}
	return allUsers[c];
}
user* hr_driver()
{
	driver* d;
	double max = -1, rating=0;
	int c = 0;
	for (int i = 0; i < (int)allUsers.size(); i++)
	{
		rating = allUsers[i]->getAvgRating();
		d = dynamic_cast<driver*>(allUsers[i]);
		if (d != nullptr && rating > max)
		{
			max = rating;
			c = i;
		}
	}
	return allUsers[c];
}
void user_des(const user* U)
{
	for (int i = 0; i < (int)allUsers.size(); i++)
	{
		if (allUsers[i] == U)
			allUsers.erase(allUsers.begin() + i);
	}
}

int main()
{
	
	/*driver *d1= new driver("D1", Date(16,1,1990), "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917");
	passenger* p1 = new passenger("P1", Date(10, 10, 1990), "ali@yahoo.com", "0334564334", payment("111-222-333-333", "card"));
		
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

	p1->printTrips();
	cout << "\n----------------------------\n\n";
	d1->printTrips();
	cout << p1->getAvgRating() << endl;
	cout << d1->getAvgRating() << endl;
		
	printAllUsers();
	system("cls");

	read_file("input.txt");

	cout << *(hr_user()) << endl;
	cout <<hr_user()->getAvgRating() << endl;
	cout << "---------------\n\n";
	cout << *(hr_driver()) << endl;
	cout << hr_driver()->getAvgRating() << endl;
	cout << "---------------\n\n";
	cout << *(hr_passenger()) << endl;
	cout << hr_passenger()->getAvgRating() << endl;

	for (int i = 0; i < (int)uberTrips.size(); i++)
	{
		if(uberTrips[i]>0)
			delete uberTrips[i];
	}
	uberTrips.clear();

	delete p1;
	delete d1;

	for (int i = 0; i < (int)allUsers.size(); i++)
	{
		if(allUsers[i]>0)
			delete allUsers[i];
	}
	allUsers.clear();*/
	
	read_file("input.txt");
	addToUberTrips(allUsers[0]->bookRide("a","b"));
	allUsers[1]->pickARide(uberTrips[0]);
	allUsers[1]->endARide();
	allUsers[0]->rateDriver(uberTrips[0],5);
	allUsers[1]->ratePassanger(uberTrips[0],4);
	cout << endl;
	addToUberTrips(allUsers[2]->bookRide("a", "b"));
	allUsers[1]->pickARide(uberTrips[1]);
	allUsers[1]->endARide();
	allUsers[1]->ratePassanger(uberTrips[1], 3);
	allUsers[2]->rateDriver(uberTrips[1], 4);
	cout << endl;
	addToUberTrips(allUsers[5]->bookRide("a", "b"));
	allUsers[1]->pickARide(uberTrips[2]);
	allUsers[1]->endARide();
	allUsers[5]->rateDriver(uberTrips[2], 5);
	allUsers[1]->ratePassanger(uberTrips[2], 4);


	system("PAUSE");
	return 0;
}