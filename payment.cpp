/*
File made by Abdul Saboor (20L-1113 / BDS 2A) on 21/6/2021
*/
#include"payment.h"

payment::payment(const string& C,const string& M):card_num{C},mode{M}
{}

payment::payment(const string& M) : card_num{"" }, mode{ M }
{}

ostream& operator<<(ostream& out, const payment& P)
{
	cout << P.card_num << endl << P.mode;
	return out;
}