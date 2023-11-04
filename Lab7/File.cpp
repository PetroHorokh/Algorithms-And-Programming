#include "Header.h"

int File::PrintFile()
{
	const auto FileToStack = new string(
		(istreambuf_iterator<char>(*make_unique<ifstream>(FileName))), istreambuf_iterator<char>());

	if (FileToStack->empty())
	{
		cout << "\nSomething wrong with file!" << endl;
		delete FileToStack;
		return -1;
	}

	string Line;
	stringstream str(*FileToStack);

	while (getline(str, Line, '\n'))  cout << Line << endl;

	cout << "File is read!" << endl;
	delete FileToStack;

	return 1;
}