#include "Header.h"

int CASA::CasaCount = 0;

CASA::CASA() :CasaNum(0), TicketCount(1), TicketNum(0), Name("Noname"), WorkHours("No info"), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	CasaCount++;
}
CASA::CASA(int Num) : CasaNum(Num), TicketCount(1), TicketNum(0), Name("Noname"), WorkHours("No info"), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	CasaCount++;
}
CASA::CASA(int Num, int TicketCount) : CasaNum(Num), TicketCount(TicketCount), TicketNum(0), Name("Noname"), WorkHours("No info"), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	CasaCount++;
}
CASA::CASA(int Num, int TicketCount, int Tik) : TicketNum(Tik), TicketCount(TicketCount), Name("Noname"), WorkHours("No info"), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	CasaNum = Num;

	CasaCount++;
}
CASA::CASA(int Num, int TicketCount, int Tik, string Client) :TicketNum(Tik), TicketCount(TicketCount), WorkHours("No info"), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{
	CasaNum = Num;
	Name = Client;

	CasaCount++;
}
CASA::CASA(int Num, int TicketCount, int Tik, string Client, string Work) :TicketNum(Tik), TicketCount(TicketCount), Cash(0), CashBeforeCollection(1000), TicketPrice(100)
{

	CasaNum = Num;
	Name = Client;
	WorkHours = Work;

	CasaCount++;
}
CASA::CASA(int Num, int TicketCount, int Tik, string Client, string Work, int EndCash) :TicketNum(Tik), TicketCount(TicketCount), Cash(0), TicketPrice(100)
{
	CasaNum = Num;
	Name = Client;
	WorkHours = Work;
	CashBeforeCollection = EndCash;

	CasaCount++;
}
CASA::CASA(int Num, int TicketCount, int Tik, string Client, string Work, int EndCash, int Price) :TicketNum(Tik), TicketCount(TicketCount), Cash(0)
{
	CasaNum = Num;
	Name = Client;
	WorkHours = Work;
	CashBeforeCollection = EndCash;
	TicketPrice = Price;

	CasaCount++;
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
	cout << "\nInfo about casa: "<< endl;


	cout << "Casa number = " << CasaNum << endl;
	cout << "Surname of passager = " << Name << endl;
	cout << "Working hours = " << WorkHours << endl;
	cout << "Amount of cash before collection = " << CashBeforeCollection << endl;
	cout << "Ticket price = " << TicketPrice << endl;
	cout << "Ticket number =" << TicketNum << endl;
	cout << "Tickets amount =" << TicketCount << endl;

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
	cout << "Method without parameters!" << endl;
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

ostream& operator<<(ostream& os, const CASA& obj)
{
	int w = 15;

	cout << "\nInfo about casa: \n" << endl;

	cout << setw(w) << "| Casa number = " << obj.CasaNum <<
		setw(w) << "| Surname of passager = " << obj.Name <<
		setw(w) << "| Working hours = " << obj.WorkHours <<
		setw(w) << "| Amount of cash before collection = " << obj.CashBeforeCollection <<
		setw(w) << "| Ticket price = " << obj.TicketPrice << " |\n";

	cout << "Count of casa = " << obj.CasaCount << endl;

	return os;
}
istream& operator>>(istream& is, CASA& obj)
{
	cout << "\nEnter casa info: " << endl;
	obj.CasaNum = StrToInt("\nEnter casa number = ");
	cout << "\nEnter Name of passager = ";
	getline(cin, obj.Name);
	cout << "\nEnter working hours = ";
	getline(cin, obj.WorkHours);
	obj.CashBeforeCollection = StrToInt("\nEnter amount of cash before collection = ");
	obj.TicketPrice = StrToInt("\nEnter ticket price = ");
	return is;
}

fstream& operator<<(fstream& os, const CASA& obj)
{
	if (!os) {
		cout << "Cannot open file!" << endl;
		return os;
	}

	os.write((char*)&obj, sizeof(CASA));

	os.close();

	return os;
}
ifstream& operator>>(ifstream& is, CASA& obj)
{
	if (!is) {
		cout << "Cannot open file!" << endl;
		return is;
	}

	is.read((char*)&obj, sizeof(CASA));

	is.close();

	return is;
}

bool CASA::operator>(const CASA& obj)
{
	return (CasaNum > obj.CasaNum);
}
bool CASA::operator<(const CASA& obj)
{
	return (CasaNum < obj.CasaNum);
}
bool CASA::operator<=(const CASA& obj)
{
	return (CasaNum <= obj.CasaNum);
}
bool CASA::operator>=(const CASA& obj)
{
	return (CasaNum >= obj.CasaNum);
}
bool CASA::operator==(const CASA& obj)
{
	return (CasaNum == obj.CasaNum);
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

CASA* FileToArr(int& len)
{
	string filename = "Casa.dat";
	ifstream f(filename, ios::binary);
	f.seekg(0, 2);
	len = f.tellg() / sizeof(CASA);
	f.seekg(0);
	CASA* arr = new CASA[len];

	int i = 0;

	f >> arr[i++];

	while (!f.eof())
	{
		f >> arr[i++];
	}

	f.close();

	return arr;
}
void CasaPrint(CASA* arr, int len, string msg)
{
	cout << msg << endl;

	for(int i = 0; i < len; i++)
	{
		cout << arr[i];
	}
}
