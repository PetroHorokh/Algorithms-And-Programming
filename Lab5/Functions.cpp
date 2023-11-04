#include "Header.h"

CASA** CreatArray(int& len)
{
	int BusCasaAmount = StrToInt("How many elements of BusCasa are you willing to creat?: ");
	int PlaneCasaAmount = StrToInt("How many elements of PlaneCasa are you willing to creat?: ");

	len = BusCasaAmount + PlaneCasaAmount;

	CASA** ACasa = new CASA* [len];

	for (int i = 0; i < BusCasaAmount; i++)
	{
		ACasa[i] = new BusCasa();
	}
	for (int i = BusCasaAmount; i < len; i++)
	{
		ACasa[i] = new PlaneCasa();
	}

	return ACasa;
}

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

void DeleteArray2D(CASA** arr, int len)
{
	for (int i = 0; i < len; i++) delete arr[i];

	delete[] arr;

	cout << "\nArray deleted!\n" << endl;
}