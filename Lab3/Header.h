#pragma warning (disable :4996)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime> 

using namespace std;

class TICKET
{
protected:
	int TicketNumber;
	string ClientName;

public:
	void setNumber(int);
	void setName(string);

	int getNumber();
	string getName();

	int Read();
	int Write();
};

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

	TICKET tik;

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

	void InputTicket();
	void OutputTicket();

	int Read();
	int Write();

	int DonloadCasaToFile();
	int OutLoadCasaFromFile();

	int DonloadTicketToFile();
	int OutLoadTicketFromFile();
};

int StrToInt(string);
string IntToStr(int);