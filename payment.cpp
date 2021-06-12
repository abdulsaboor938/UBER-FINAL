#include"payment.h"

Payment::Payment(const string& C,const string& M):card_num{C},mode{M}
{}

ostream& operator<<(ostream& out, const Payment& P)
{
	cout << P.card_num << "," << P.mode << endl;
	return out;
}