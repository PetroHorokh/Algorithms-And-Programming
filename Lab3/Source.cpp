#include "Header.h"

int CASA::CasaCount = 0;

CASA::CASA():CasaNum(0), TicketCount(1), TicketNum(0), Name("Noname"), WorkHours("No info"), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	CasaCount++;
}
CASA::CASA(int Num):CasaNum(Num), TicketCount(1) , TicketNum(0), Name("Noname"), WorkHours("No info"), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	CasaCount++;
}
CASA::CASA(int Num, int TicketCount) : CasaNum(Num), TicketCount(TicketCount), TicketNum(0), Name("Noname"), WorkHours("No info"), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	CasaCount++;
}
CASA::CASA(int Num, int TicketCount, int Tik):TicketNum(Tik), TicketCount(TicketCount), Name("Noname"), WorkHours("No info"), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	CasaNum = Num;

	CasaNum++;
}
CASA::CASA(int Num, int TicketCount, int Tik, string Client):TicketNum(Tik), TicketCount(TicketCount), WorkHours("No info"), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	CasaNum = Num;
	Name = Client;

	CasaNum++;
}
CASA::CASA(int Num, int TicketCount, int Tik, string Client, string Work):TicketNum(Tik), TicketCount(TicketCount), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	
	CasaNum = Num;
	Name = Client;
	WorkHours = Work;

	CasaNum++;
}
CASA::CASA(int Num, int TicketCount, int Tik, string Client, string Work, int EndCash):TicketNum(Tik), TicketCount(TicketCount), Cash(0), TicketPrice(100)
{
	CasaNum = Num;
	Name = Client;
	WorkHours = Work;
	CashBeforeCollection = EndCash;

	CasaNum++;
}
CASA::CASA(int Num, int TicketCount, int Tik, string Client, string Work, int EndCash, int Price):TicketNum(Tik), TicketCount(TicketCount), Cash(0)
{
	CasaNum = Num;
	Name = Client;
	WorkHours = Work;
	CashBeforeCollection = EndCash;
	TicketPrice = Price;

	CasaNum++;
}
CASA::~CASA()
{
	CasaCount--;
	cout << "Destuctor \n";
}
CASA::CASA(const CASA& obj)
{
	CasaNum = obj.CasaNum;
	TicketCount = obj.TicketCount;
	Name = obj.Name;
	WorkHours = obj.WorkHours;
	Cash = obj.Cash;
	CashBeforeCollection = obj.CashBeforeCollection;
	TicketPrice = obj.TicketPrice;

	CasaCount++;
}

void CASA::OutputCasa()
{
	cout << "\nInfo about casa: \n" << endl;

	cout << "Casa number = " << CasaNum << endl;
	cout << "Surname of passager = " << Name << endl;
	cout << "Working hours = " << WorkHours << endl;
	cout << "Amount of cash before collection = " << CashBeforeCollection << endl;
	cout << "Ticket price = " << TicketPrice << endl;

	cout << "Count of casa = " << CasaCount << endl;
}
void CASA::InputCasa()
{
	CasaNum = StrToInt("\nEnter casa number = ");
	cout << "\nEnter Name of passager = ";
	getline(cin, Name);
	cout << "\nEnter working hours = ";
	getline(cin, WorkHours);
	CashBeforeCollection = StrToInt("\nEnter amount of cash before collection = ");
	TicketPrice = StrToInt("\n Enter ticket price = ");
}

void CASA::Sell()
{
	cout <<"Method without parameters!" << endl;
}
void CASA::Sell(int TicketCount)
{
	cout << "Working method with parameters" << endl;
	cout << "Anount of tickets: " << TicketCount << endl;
	Cash += TicketPrice * TicketCount;
	cout << "Amount of cash: " << Cash << endl;
	cout << "Working with: " << Name << endl;
}

string CASA::getWorkingHours()
{
	return WorkHours;
}
int CASA::getCash()
{
	return Cash;
}
int CASA::getCashBeforeCollection()
{
	return CashBeforeCollection;
}
int CASA::getTicketPrice()
{
	return TicketPrice;
}
int CASA::getCasaNum()
{
	return CasaNum;
}
int CASA::getCountCasa()
{
	return CasaCount;
}
int CASA::getTicketCount()
{
	return TicketCount;
}

void CASA::setTicketCount(int TikC)
{
	TicketCount = TikC;
}

int TICKET::getNumber()
{
	return TicketNumber;
}
string TICKET::getName()
{
	return ClientName;
}

void TICKET::setNumber(int Num)
{
	TicketNumber = Num;
}
void TICKET::setName(string Client)
{
	ClientName = Client;
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

int TICKET::Write()
{
	ofstream f("Ticket.dat", ios::binary);

	//fstream f(name, ios::app |ios::binary);

	if (!f) {
		cout << "Cannot open file!" << endl;
		return -1;
	}

	f.write((char*) this, sizeof(TICKET));

	f.close();

	if (!f.good()) {
		cout << "Error occurred at writing time!" << endl;
		return 0;
	}
	
	return 1;
}
int TICKET::Read()
{
	ifstream f("Ticket.dat", ios::binary);

	if (!f) {
		cout << "Cannot open file!" << endl;
		return -1;
	}

	f.read((char*)this, sizeof(TICKET));

	f.close();

	if (!f.good()) 
	{
		cout << "Error occurred at reading time!" << endl;
		return 0;
	}

	return 1;
}

int CASA::Write()
{
	ofstream f("Casa.dat", ios::binary);

	//fstream f(name, ios::app |ios::binary);

	if (!f) {
		cout << "Cannot open file!" << endl;
		return -1;
	}

	f.write((char*)this, sizeof(CASA));

	f.close();

	if (!f.good()) {
		cout << "Error occurred at writing time!" << endl;
		return 0;
	}

	return 1;
}
int CASA::Read()
{
	ifstream f("Casa.dat", ios::binary);

	if (!f) {
		cout << "Cannot open file!" << endl;
		return -1;
	}

	f.read((char*)this, sizeof(CASA));

	f.close();

	if (!f.good())
	{
		cout << "Error occurred at reading time!" << endl;
		return 0;
	}

	return 1;
}

int CASA::DonloadCasaToFile()
{
	return Write();
}
int CASA::OutLoadCasaFromFile()
{
	return Read();
}

int CASA::DonloadTicketToFile()
{
	return tik.Write();
}
int CASA::OutLoadTicketFromFile()
{
	return tik.Read();
}

void CASA::InputTicket()
{
	tik.setName(Name);
	tik.setNumber(TicketNum);
}
void CASA::OutputTicket()
{
	cout << "\nInfo about ticket: \n" << endl;
	cout << "Ticket number = " << tik.getNumber() << endl;
	cout << "Ticket name = " << tik.getName() << endl;
	cout << "Amount of tickets" << TicketCount << endl;
}
