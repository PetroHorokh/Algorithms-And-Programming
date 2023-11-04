#include "Header.h"

void BusCasa::OutputCasa()
{
	int w = 15;

	cout << "\nInfo about casa: \n" << endl;

	cout << setw(w) << "| Casa number = " << getCasaNum() <<
		setw(w) << " | Bus number = " << BusNum <<
		setw(w) << " | Surname of passager = " << Name <<
		setw(w) << " | Working hours = " << getWorkingHours() <<
		setw(w) << " | Amount of cash before collection = " << getCashBeforeCollection() <<
		setw(w) << " | Ticket price = " << getTicketPrice() << " |\n";

	cout << "Count of casa = " << getCountCasa() << endl;
}
void BusCasa::InputCasa()
{
	string WorkHours;

	setCasaNum(StrToInt("\nEnter casa number = "));
	cout << "Enter bus nember = ";
	cin >> BusNum;
	cout << "\nEnter Name of passager = ";
	getline(cin, Name);
	cout << "\nEnter working hours = ";
	getline(cin, WorkHours);
	setCashBeforeCollection(StrToInt("\nEnter amount of cash before collection = "));
	setTicketPrice(StrToInt("\n Enter ticket price = "));
	setWorkingHours(WorkHours);
}

int BusCasa::Write(string filename)
{
	ofstream f(filename, ios::binary);

	if (!f) {
		cout << "Cannot open file!" << endl;
		return -1;
	}

	f.write((char*)this, sizeof(CASA));

	f.close();

	return 1;
}
int BusCasa::Read(string filename)
{
	ifstream f(filename, ios::binary);

	if (!f) {
		cout << "Cannot open file!" << endl;
		return -1;
	}

	f.read((char*)this, sizeof(CASA));

	f.close();

	return 1;
}

int BusCasa::DonloadCasaToFile()
{
	return Write("BusCasa.dat");
}
int BusCasa::OutLoadCasaFromFile()
{
	return Read("BusCasa.dat");
}

ostream& operator<<(ostream& os, BusCasa& obj)
{
	int w = 15;

	cout << "\nInfo about casa: \n" << endl;

	cout << setw(w) << "| Casa number = " << obj.getCasaNum() <<
		setw(w) << " | Bus number = " << obj.getBusNum() <<
		setw(w) << " | Surname of passager = " << obj.Name <<
		setw(w) << " | Working hours = " << obj.getWorkingHours() <<
		setw(w) << " | Amount of cash before collection = " << obj.getCashBeforeCollection() <<
		setw(w) << " | Ticket price = " << obj.getTicketPrice() << " |\n";

	cout << "Count of casa = " << obj.getTicketCount() << endl;

	return os;
}
istream& operator>>(istream& is, BusCasa& obj)
{
	string WorkHours;

	cout << "\nEnter casa info: " << endl;
	obj.setCasaNum(StrToInt("\nEnter casa number = "));
	obj.setBusNum(StrToInt("\nEnter bus number = "));
	cout << "\nEnter Name of passager = ";
	getline(cin, obj.Name);
	cout << "\nEnter working hours = ";
	getline(cin, WorkHours);
	obj.setCashBeforeCollection(StrToInt("\nEnter amount of cash before collection = "));
	obj.setTicketPrice(StrToInt("\nEnter ticket price = "));

	obj.setWorkingHours(WorkHours);

	return is;
}

fstream& operator<<(fstream& os, const BusCasa& obj)
{
	if (!os) {
		cout << "Cannot open file!" << endl;
		return os;
	}

	os.write((char*)&obj, sizeof(BusCasa));

	os.close();

	return os;
}
ifstream& operator>>(ifstream& is, BusCasa& obj)
{
	if (!is) {
		cout << "Cannot open file!" << endl;
		return is;
	}

	is.read((char*)&obj, sizeof(BusCasa));

	return is;
}

void BusCasa::FileToArr(BusCasa*& a, int& len)
{
	string filename = "BusCasa.dat";
	ifstream f(filename, ios::binary);
	f.seekg(0, 2);
	len = (int)(f.tellg()) / sizeof(BusCasa);
	f.seekg(0);
	BusCasa* arr = new BusCasa[len];

	int i = 0;

	f >> arr[i++];

	while (!f.eof())
	{
		f >> arr[i++];
	}

	f.close();

	a = arr;
}