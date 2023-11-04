#pragma warning (disable :4996)

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <iomanip>

using namespace std;

class CASAFUNCTIONS
{
public:
	virtual void OutputCasa() = 0;
	virtual void InputCasa() = 0;

	virtual void sell() = 0;
	virtual void sell(int TicketCount) = 0;

	virtual int Read(string filename) = 0;
	virtual int Write(string filename) = 0;

	virtual int DonloadCasaToFile() = 0;
	virtual int OutLoadCasaFromFile() = 0;
};

class CASANUMBERISE
{
public:
	virtual void Numberise() = 0;
};

class CASA : public CASAFUNCTIONS
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

	virtual void OutputCasa();
	virtual void InputCasa();

	void CasaPrint(CASA*, int, string);

	virtual void sell();
	virtual void sell(int TicketCount);

	static int getCountCasa();

	int getCasaNum();
	string getWorkingHours();
	int getCash();
	int getCashBeforeCollection();
	int getTicketPrice();
	int getTicketCount();

	void setCasaNum(int Num) { CasaNum = Num; };
	void setWorkingHours(string Time) { WorkHours = Time; };
	void setCash(int Money) { Cash = Money; };
	void setCashBeforeCollection(int Money) { CashBeforeCollection = Money; };
	void setTicketPrice(int Tik) { TicketPrice = Tik; };
	void setTicketCount(int Tik) { TicketCount = Tik; };

	virtual int Read(string filename);
	virtual int Write(string filename);

	virtual int DonloadCasaToFile();
	virtual int OutLoadCasaFromFile();

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

class BusCasa : public CASA
{
private:
	int BusNum;

public:
	BusCasa() : CASA() ,BusNum(0) {};
	BusCasa(CASA(tp), int num) : CASA(tp), BusNum(num) {};

	int getBusNum() { return BusNum; };

	void setBusNum(int Num) { BusNum = Num; };

	void FileToArr(BusCasa*& arr, int& len);

	virtual int Read(string filename);
	virtual int Write(string filename);

	virtual int DonloadCasaToFile();
	virtual int OutLoadCasaFromFile();

	virtual void OutputCasa();
	virtual void InputCasa();

	friend ostream& operator<<(ostream& os, BusCasa& obj);
	friend istream& operator>>(istream& is, BusCasa& obj);

	friend fstream& operator<<(fstream& os, const BusCasa& obj);
	friend ifstream& operator>>(ifstream& is, BusCasa& obj);
};

class PlaneCasa : public CASA
{
private:
	int PlaneNum;

public:
	PlaneCasa() : CASA(), PlaneNum(0) {};
	PlaneCasa(CASA(tp), int num) : CASA(tp), PlaneNum(num) {};

	virtual ~PlaneCasa() { cout << "Plane casa destructior!" << endl; };

	int getPlaneNum() { return PlaneNum; };

	void setPlaneNum(int Num) { PlaneNum = Num; };

	void FileToArr(PlaneCasa*& arr, int& len);

	virtual int Read(string filename);
	virtual int Write(string filename);

	virtual int DonloadCasaToFile();
	virtual int OutLoadCasaFromFile();

	virtual void OutputCasa();
	virtual void InputCasa();

	friend ostream& operator<<(ostream& os, PlaneCasa& obj);
	friend istream& operator>>(istream& is, PlaneCasa& obj);

	friend fstream& operator<<(fstream& os, PlaneCasa& obj);
	friend ifstream& operator>>(ifstream& is, PlaneCasa& obj);
};

int StrToInt(string);
string IntToStr(int);

CASA** CreatArray(int&);

void DeleteArray2D(CASA** arr, int len);