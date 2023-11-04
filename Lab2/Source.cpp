#include"Header.h"

char* FindAndEnterFile() {
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char buffer[MAX_PATH];
	GetCurrentDirectory(sizeof(buffer), buffer);
	hFind = FindFirstFile("*.txt", &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "Invalid File Handle. GetLastError() reports " << (double)GetLastError();
		return nullptr;
	}
	cout << FindFileData.cFileName << endl;
	while (FindNextFile(hFind, &FindFileData) != 0)
	{
		cout << FindFileData.cFileName << endl;
	}
	FindClose(hFind);

	char filename[FILENAME_SIZE+1];
	cout << "enter file: ";
	cin.getline(filename, FILENAME_SIZE);
	return filename;
}

int FilePrint(const char* filename)
{
	ifstream fin(filename);

	if (!fin)
	{
		puts("FILE NOT OPEN!");
		return 0;
	}

	char str[SIZE_S + 1];
	bool flag = false;

	while (!fin.eof()) {
		flag = true;
		if (fin.getline(str, SIZE_S))
			printf("%s\n", str);
	}

	if (!flag)
	{
		puts("FILE IS EMPTY!\n");
	}

	fin.close();

	return 1;
}

STACK* LoadFileToStack(const char* filename, int& size)
{
	ifstream fin(filename);

	if (!fin)
	{
		puts("FILE NOT OPEN!");
		return 0;
	}

	char str[SIZE_S + 1];
	bool flag = false;

	STACK* ptr = NULL;

	while (!fin.eof()) {
		flag = true;
		size++;
		if (fin.getline(str, SIZE_S))
		{
			push(ptr, str);
		}
	}

	if (!flag)
	{
		puts("FILE IS EMPTY!\n");
	}

	fin.close();

	return ptr;
}

void pop(STACK* ptr)
{
	printf("%s\n", &*ptr->txt);
}

void push(STACK*& ptr, char* str)
{
	STACK* st = new STACK;
	st->txt = new char[strlen(str) + 1];
	strcpy(st->txt, str);
	st->sptr = ptr;
	ptr = st;
}

int PrintStack(STACK* ptr)
{
	if (!ptr) return 0;
	while (ptr)
	{
		pop(ptr);
		ptr = ptr->sptr;
	}
	return 1;
}

int purge(STACK*& ptr)
{
	if (!ptr) return 0;

	STACK* head;
	while (ptr)
	{
		pop(ptr);

		head = ptr->sptr;
		delete ptr;
		ptr = head;
	}
	return 1;
}

int renumber(STACK*& ptr, int size)
{
	if (!size) return 0;

	int i = size;
	STACK* st = ptr;

	while (ptr)
	{
		char* tmp = new char[strlen(ptr->txt) + 10];

		strcat(itoa(i, tmp, 10), " : ");
		strcat(tmp, ptr->txt);

		delete[]ptr->txt;

		ptr->txt = tmp;

		i--;
		ptr = ptr->sptr;
	}

	ptr = st;

	return 1;
}

int menu()
{
	cout << "\nMENU:\n";

	printf("%i%s\n", choosefile, " - CHOOSE ANOTHER FILE FROM CURRENT DIRECTORY");
	printf("%i%s\n", printfile, " - PRINT TEXT IN FILE");
	printf("%i%s\n", filetostack, " - CONVERT TEXT FROM FILE TO STACK");
	printf("%i%s\n", numberesation, " - NUMBER ALL LINES OF TEXT IN STACK");
	printf("%i%s\n", printstack, " - PRINT STACK");
	printf("%i%s\n", deletestack, " - DELETE STACK");
	printf("%i%s\n", endprogram, " - END PROGRAM");

	printf("\n%s ", "YOUR CHOISE:");

	const int choisesize = 10;
	char choise[choisesize+1];

	cin.getline(choise, choisesize);

	return atoi(choise);
}

int Main()
{
	int choise, line_counter = 0;
	char filename[FILENAME_SIZE+1];

	STACK* ptr = NULL;

	while (1)
	{
		choise = menu();

		cin.clear();

		switch (choise)
		{
		case choosefile:
			if (!strcpy(filename, FindAndEnterFile())) return 1;
			break;
		case printfile:
			if (FilePrint(filename) != 1) printf("\n%s\n", "FILE NOT AVAILABLE!");
			break;
		case filetostack:
			if (!(ptr = LoadFileToStack(filename, line_counter))) printf("\n%s\n", "CHOOSE ANOTHER FILE");
			break;
		case numberesation:
			if (!renumber(ptr, line_counter)) printf("\n%s\n","NOTHING TO NUMERIZE");
			break;
		case printstack:
			if(!PrintStack(ptr)) printf("\n%s\n", "NO STACK TO PRINT");
			break;
		case deletestack:
			if(!purge(ptr)) printf("\n%s\n", "NO STACK TO DELETE");
			break;
		case endprogram:
			return 1;

		default:
			cout << "Wrong choise! Enter again\n";
			break;
		}
	}
	return 1;
}
