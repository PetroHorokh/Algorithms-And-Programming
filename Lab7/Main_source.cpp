#include "Header.h"

int Main::menu()
{
	cout << "\nMENU:\n";

	cout <<  choosefile << " - CHOOSE ANOTHER FILE FROM CURRENT DIRECTORY" << endl;
	cout << printfile << " - PRINT TEXT IN FILE" << endl;
	cout << filetostack << " - CONVERT TEXT FROM FILE TO STACK" << endl;
	cout << numeresation << " - NUMBER ALL LINES OF TEXT IN STACK" << endl;
	cout << reversestack << " - REVERSE STACK" << endl;
	cout << addstring << " - ADD STRING TO STACK" << endl;
	cout << gettop << " - GET TOP OF STACK" << endl;
	cout << printstack << " - PRINT STACK" << endl;
	cout << deletestack << " - DELETE STACK" << endl;
	cout << endprogram << " - END PROGRAM" << endl;

	cout << "YOUR CHOISE:";

	string choise;

	getline(cin,choise);

	cout << endl;

	return stoi(choise);
}

int Main::Main_menu()
{
	STACK Stack;
	int choise = 0;


	while ((choise = menu()) != endprogram)
	{
		switch (choise)
		{
		case choosefile:
			Stack.Choise_File();
			if (Stack.filename == "noname") cout << "Entered incorrect file name!" << endl;

			break;
		case printfile:
			if (Stack.filename == "noname") cout << "File not open!" << endl;
			else Stack.Print_File();

			break;
		case filetostack:
			if(Stack.FileToStack() < 1) cout << "Something wrong with reading to stack!" << endl;

			break;

		case numeresation:
			Stack.Numerise();

			break;
		case reversestack:
			Stack.StackRevers();

			break;
		case addstring:
			Stack.AddStringToStack();

			break;
		case gettop:
			Stack.GetTop();

			break;
		case printstack:
			Stack.StackOutput();

			break;
		case deletestack:
			Stack.DeleteStack();

			break;
		case endprogram:
			break;

		default:
			cout << "Wrong choise! Enter again\n";
			break;
		}
	}

	return 1;
}