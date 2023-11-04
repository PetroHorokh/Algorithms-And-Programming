#include"Header.h"

void STACK::Choise_File()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char buffer[MAX_PATH];
	GetCurrentDirectory(sizeof(buffer), buffer);
	hFind = FindFirstFile("*.txt", &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "Invalid File Handle. GetLastError() reports " << (double)GetLastError();
		filename = "noname";
		return;
	}
	cout << FindFileData.cFileName << endl;
	while (FindNextFile(hFind, &FindFileData) != 0)
	{
		cout << FindFileData.cFileName << endl;
	}
	FindClose(hFind);

	cout << "Enter file: ";
	getline(cin, filename);

	cout << "\n\tFile chosen\n" << endl;
}

void STACK::Print_File()
{
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "\n\tSomething wrong with file\n" << endl;
		return;
	}

	istreambuf_iterator<char>fin(file);
	istreambuf_iterator<char>eoa;
	ostreambuf_iterator<char>cout_it(cout);

	copy(fin, eoa, cout_it);

	cout << "\n\tFile is read!\n" << endl;
}

int STACK::FileToStack()
{
	const auto FileToStack = new string((istreambuf_iterator<char>(*make_unique<ifstream>(filename))),istreambuf_iterator<char>());
	
	if (FileToStack->empty())
	{
		cout << "\nSomething wrong with file!" << endl;
		delete FileToStack;
		return 0;
	}
	
	string Line;
	stringstream str(*FileToStack);
	
	while (getline(str, Line, '\n'))  Stack.push(Line);
	
	cout << "Stack created" << endl;
	delete FileToStack;

	return 1;
}

void STACK::Numerise()
{
	if (Stack.empty())
	{
		cout << "Stack is empty!" << endl;
		return;
	}

	StackRevers();

	auto tmp_Stack = Stack;
	int i = 0;

	DeleteStack();

	while (!tmp_Stack.empty())
	{
		Stack.push(tmp_Stack.top().insert(0, to_string(++i) + ": "));
		tmp_Stack.pop();
	}

	StackRevers();

	cout << endl;
}

void STACK::DeleteStack()
{
	if (Stack.empty())
	{
		cout << "Stack is empty!" << endl;
		return;
	}

	if (Stack.empty()) cout << "Stack is empty";
	else while (!Stack.empty()) Stack.pop();
}

void STACK::StackOutput()
{
	if (Stack.empty())
	{
		cout << "Stack is empty!" << endl;
		return;
	}

	auto tmp_Stack = Stack;

	while (!tmp_Stack.empty())
	{
		cout << tmp_Stack.top() << endl;
		tmp_Stack.pop();
	}
	cout << endl;
}

void STACK::StackRevers()
{
	if (Stack.empty())
	{
		cout << "Stack is empty!" << endl;
		return;
	}

	auto tmp_Stack = Stack;

	DeleteStack();

	while (!tmp_Stack.empty())
	{
		Stack.push(tmp_Stack.top());
		tmp_Stack.pop();
	}
}

void STACK::AddStringToStack()
{
	string str;

	cout << "Enter string to add to stack: ";

	getline(cin, str);

	Stack.push(str);
}

void STACK::GetTop()
{
	if (Stack.empty())
	{
		cout << "Stack is empty!" << endl;
		return;
	}

	cout << "Head of stack is: " << Stack.top() << endl;
	Stack.pop();

	cout << "Head was extracted!" << endl;
}
