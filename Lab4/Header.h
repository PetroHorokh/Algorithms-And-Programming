#pragma warning (disable :4996)

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <iomanip>

using namespace std;

class CASA
{
private:
	static int CasaCount;

	int CasaNum;
	string WorkHours;
	int Cash;
	int CashBeforeCollection;
	int TicketPrice;


protected:
	int TicketNum;
	int TicketCount;

public:
	string Name;

	CASA();

	CASA(int CasaNum);
	CASA(int CasaNum, int TicketCount);
	CASA(int CasaNum, int TicketCount, int Tik);
	CASA(int CasaNum, int TicketCount, int Tik, string Name);
	CASA(int CasaNum, int TicketCount, int Tik, string Name, string WorkHours);
	CASA(int CasaNum, int TicketCount, int Tik, string Name, string WorkHours, int CashBeforeCollection);
	CASA(int CasaNum, int TicketCount, int Tik, string Name, string WorkHours, int CashBeforeCollection, int TicketPrice);
	CASA(const CASA&);
	~CASA();

	void OutputCasa();
	void InputCasa();

	void Sell();
	void Sell(int TicketCount);

	static int getCountCasa();

	int getCasaNum();
	string getWorkingHours();
	int getCash();
	int getCashBeforeCollection();
	int getTicketPrice();
	int getTicketCount();

	void setTicketCount(int);

	int Read();
	int Write();

	int DonloadCasaToFile();
	int OutLoadCasaFromFile();

	friend ostream& operator<<(ostream& os, const CASA& obj);
	friend istream& operator>> (istream& is, CASA& obj);

	friend fstream& operator<<(fstream& os, const CASA& obj);
	friend ifstream& operator>>(ifstream& is, CASA& obj);

	bool operator>(const CASA& obj);
	bool operator<(const CASA& obj);
	bool operator<=(const CASA& obj);
	bool operator>=(const CASA& obj);
	bool operator==(const CASA& obj);
};

int StrToInt(string);
string IntToStr(int);

CASA* FileToArr(int&);
void CasaPrint(CASA*, int, string);