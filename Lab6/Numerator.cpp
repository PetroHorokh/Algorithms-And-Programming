#include "Header.h"

void NUMERATOR::CreatArray()
{
	int BusCasaAmount = StrToInt("How many elements of BusCasa are you willing to creat?: ");
	int PlaneCasaAmount = StrToInt("How many elements of PlaneCasa are you willing to creat?: ");

	LengthOfArray = BusCasaAmount + PlaneCasaAmount;

	vector<CASA*> ACasa = {};

	for (int i = 0; i < BusCasaAmount; i++)
	{
		ACasa.push_back(new BusCasa());
	}
	for (int i = BusCasaAmount; i < LengthOfArray; i++)
	{
		ACasa.push_back(new PlaneCasa());
	}

	CasaArray = ACasa;
	Separator = BusCasaAmount;
}

void NUMERATOR::OutputCasaArray(string msg)
{
	cout << msg;

	for (int i = 0; i < LengthOfArray; i++) CasaArray[i]->OutputCasa();
}

void NUMERATOR::DeleteArray2D()
{
	for (int i = 0; i < LengthOfArray; i++) delete CasaArray[i];

	cout << "\nArray deleted!\n" << endl;
}

void NUMERATOR::Numerise()
{
	for (int i = 0; i < LengthOfArray; CasaArray[i++]->setCasaNum((rand()%100)+1));
}

void NUMERATOR::Sort()
{
	sort(CasaArray.begin(), CasaArray.end(), [](CASA* a, CASA* b) { return *a < *b; });
}