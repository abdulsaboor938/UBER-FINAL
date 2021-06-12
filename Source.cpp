#include<iostream>
using namespace std;

#include"date.h"
#include"user.h"

int main()
{
	User u("abdul", Date(17, 1, 2000), "abdulsaboor938@gmail.com", "0336-66932750");
	u.print();
	cout << endl;
	u.change_name("saboor");
	u.change_DOB(Date(17, 1, 2002));
	u.change_ph("0346-6932750");
	u.print();
	cout << endl;
	system("pause");
	return 0;
}