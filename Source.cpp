#include<iostream>
using namespace std;

#include"date.h"
#include"user.h"

int main()
{
	User u("saboor", Date(17, 1, 2002), "abdulsaboor938@gmail.com", "0346-6932750");
	u.print();
	cout << endl;
	system("pause");
	return 0;
}