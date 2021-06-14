#include"payment.h"

payment::payment(const string& C,const string& M):card_num{C},mode{M}
{}

payment::payment(const string& M) : card_num{"" }, mode{ M }
{}

ostream& operator<<(ostream& out, const payment& P)
{
	cout << P.card_num << "," << P.mode << endl;
	return out;
}