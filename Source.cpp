#include<iostream>
using namespace std;

#include"date.h"
//#include"user.h"
#include"driver.h"
#include"passenger.h"
#include"payment.h"

int main()
{
	Driver u("saboor", Date(17, 1, 2002), "abdulsaboor938@gmail.com", "0334-66932750","lic1234","veh5678");
	Passenger u1("saboor", Date(17, 1, 2002), "abdulsaboor938@gmail.com", "0334-66932750",Payment("1234-5678-1234-5678","card"));
	cout << u << endl;
	cout << "---------------------" << endl;
	cout << u1 << endl;
	system("pause");
	return 0;
}