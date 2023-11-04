#include "Header.h"

int StrToInt(string msg)
{
	string snum;

	cout << msg;

	getline(cin, snum);

	return stoi(snum);
}
string IntToStr(int num)
{
	return(to_string(num));
}