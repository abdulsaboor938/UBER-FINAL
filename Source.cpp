#include<iostream>
using namespace std;

#include"date.h"
//#include"user.h"
#include"driver.h"
#include"passenger.h"

int main()
{
	//Driver u("saboor", Date(17, 1, 2002), "abdulsaboor938@gmail.com", "0334-66932750","lic1234","veh5678");
	Passenger u("saboor", Date(17, 1, 2002), "abdulsaboor938@gmail.com", "0334-66932750");
	cout << u << endl;
	system("pause");
	return 0;
}