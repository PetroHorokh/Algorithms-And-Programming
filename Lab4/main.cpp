#include"Header.h"

int main()
{
	CASA a;

	cin >> a;

	CASA b(a);

	CASA c, d;

	cin >> d;

	fstream f("Casa.dat", ios::binary | ios::app);
	ifstream ff("Casa.dat", ios::binary);

	f << a;
	f << d;
	
	int len;
	CASA* arr = FileToArr(len);

	CasaPrint(arr, len, "\nFrom file, before sorting");

	sort(arr, arr + len);

	CasaPrint(arr, len, "\nAfter sorting");

	CASA z;

	ff >> z;

	cout << z;

	f.close();
	ff.close();

	cout << "\nEnd of program!\n" << endl;

	return 0;
}