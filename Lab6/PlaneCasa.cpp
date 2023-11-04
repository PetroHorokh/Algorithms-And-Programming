#include "Header.h"

void PlaneCasa::OutputCasa()
{
	int w = 15;

	cout << "\nInfo about casa: \n" << endl;

	cout << setw(w) << "| Casa number = " << getCasaNum() <<
		setw(w) << " | Plane number = " << PlaneNum <<
		setw(w) << " | Surname of passager = " << Name <<
		setw(w) << " | Working hours = " << getWorkingHours() <<
		setw(w) << " | Amount of cash before collection = " << getCashBeforeCollection() <<
		setw(w) << " | Ticket price = " << getTicketPrice() << " |\n";

	cout << "Count of casa = " << getCountCasa() << endl;
}
void PlaneCasa::InputCasa()
{
	string WorkHours;

	setCasaNum(StrToInt("\nEnter casa number = "));
	cout << "Enter bus nember = ";
	cin >> PlaneNum;
	cout << "\nEnter Name of passager = ";
	getline(cin, Name);
	cout << "\nEnter working hours = ";
	getline(cin, WorkHours);
	setCashBeforeCollection(StrToInt("\nEnter amount of cash before collection = "));
	setTicketPrice(StrToInt("\n Enter ticket price = "));
	setWorkingHours(WorkHours);
}

int PlaneCasa::Write(string filename)
{
	ofstream f(filename, ios::binary);

	if (!f) {
		cout << "Cannot open file!" << endl;
		return -1;
	}

	f.write((char*)this, sizeof(PlaneCasa));

	f.close();

	return 1;
}
int PlaneCasa::Read(string filename)
{
	ifstream f(filename, ios::binary);

	if (!f) {
		cout << "Cannot open file!" << endl;
		return -1;
	}

	f.read((char*)this, sizeof(PlaneCasa));

	f.close();

	return 1;
}

int PlaneCasa::DonloadCasaToFile()
{
	return Write("PlaneCasa.dat");
}
int PlaneCasa::OutLoadCasaFromFile()
{
	return Read("PlaneCasa.dat");
}

ostream& operator<<(ostream& os, PlaneCasa& obj)
{
	int w = 15;

	cout << "\nInfo about casa: \n" << endl;

	cout << setw(w) << "| Casa number = " << obj.getCasaNum() <<
		setw(w) << " | Plane number = " << obj.getPlaneNum() <<
		setw(w) << " | Surname of passager = " << obj.Name <<
		setw(w) << " | Working hours = " << obj.getWorkingHours() <<
		setw(w) << " | Amount of cash before collection = " << obj.getCashBeforeCollection() <<
		setw(w) << " | Ticket price = " << obj.getTicketPrice() << " |\n";

	cout << "Count of casa = " << obj.getTicketCount() << endl;

	return os;
}
istream& operator>>(istream& is, PlaneCasa& obj)
{
	string WorkHours;

	cout << "\nEnter casa info: " << endl;
	obj.setCasaNum(StrToInt("\nEnter casa number = "));
	obj.setPlaneNum(StrToInt("\nEnter bus number = "));
	cout << "\nEnter Name of passager = ";
	getline(cin, obj.Name);
	cout << "\nEnter working hours = ";
	getline(cin, WorkHours);
	obj.setCashBeforeCollection(StrToInt("\nEnter amount of cash before collection = "));
	obj.setTicketPrice(StrToInt("\nEnter ticket price = "));

	obj.setWorkingHours(WorkHours);

	return is;
}

fstream& operator<<(fstream& os, const PlaneCasa& obj)
{
	if (!os) {
		cout << "Cannot open file!" << endl;
		return os;
	}

	os.write((char*)&obj, sizeof(PlaneCasa));

	os.close();

	return os;
}
ifstream& operator>>(ifstream& is, PlaneCasa& obj)
{
	if (!is) {
		cout << "Cannot open file!" << endl;
		return is;
	}

	is.read((char*)&obj, sizeof(PlaneCasa));

	return is;
}

void PlaneCasa::FileToArr(PlaneCasa*& a, int& len)
{
	string filename = "PlaneCasa.dat";
	ifstream f(filename, ios::binary);
	f.seekg(0, 2);
	len = (int)(f.tellg()) / sizeof(PlaneCasa);
	f.seekg(0);
	PlaneCasa* arr = new PlaneCasa[len];

	int i = 0;

	f >> arr[i++];

	while (!f.eof())
	{
		f >> arr[i++];
	}

	f.close();

	a = arr;
}