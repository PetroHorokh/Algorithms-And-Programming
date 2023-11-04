#include "Header.h"

int main()
{
	CASA a;

	a.OutputCasa();
	a.InputCasa();
	a.InputTicket();
	a.DonloadTicketToFile();
	a.OutputCasa();

	CASA b;
	b.OutLoadCasaFromFile();
	b.OutputCasa();

	b.setTicketCount(StrToInt("Enter count of tickets: "));

	a.OutLoadTicketFromFile();
	a.OutputTicket();

	a.Sell();
	a.Sell(a.getTicketCount());

	b.Sell(b.getTicketCount());

	cout << "\nEnd of program!\n" << endl;

	return 0;
}