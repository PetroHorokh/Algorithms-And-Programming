#include"Header.h"

int FilePrint(const char* filename )
{	
	FILE* file = fopen(filename, "r");

	if (!file)
	{
		puts("File not open!");
		return 0;
	}

	char str[SIZE_S+1];
	bool flag = false;

	while (!feof(file)) {
		flag = true;
		if (fgets(str, SIZE_S+1, file))
			printf("%s", str);
	}

	if (!flag)
	{
		puts("File is empty!\n");
		return -1;
	}

	fclose(file);

	return 1;
 }

STACK* LoadFileToStack(const char* filename, int& size)
{
	FILE* file = fopen(filename, "r");

	if (!file)
	{
		puts("File not open!");
		return 0;
	}

	char str[SIZE_S + 1];
	bool flag = false;

	STACK* ptr = NULL;

	while (!feof(file)) {
		flag = true;
		size++;
		if (fgets(str, SIZE_S + 1, file))
		{
			push(ptr, str);
		}
	}

	if (!flag)
	{
		puts("File is empty!\n");
	}

	fclose(file);

	return ptr;
}

void pop(STACK* ptr)
{
	printf("%s", ptr->txt);
}

void push(STACK*& ptr, char* str)
{
	STACK* st = new STACK;
	st->txt = new char[strlen(str)+1];
	strcpy(st->txt, str);
	st->sptr = ptr;
	ptr = st;
}

void PrintStack(STACK* ptr)
{
	if (!ptr)
	{
		puts("Stack is empty!");
		return;
	}

	while (ptr)
	{
		pop(ptr);
		ptr = ptr->sptr;
	}
}

void purge(STACK*& ptr)
{
	STACK* head;
	while(ptr)
	{
		pop(ptr);

		head = ptr->sptr;
		delete ptr;
		ptr = head;
	}
}

void renumber(STACK*& ptr, int size)
{
	int i = size;
	STACK* st = ptr;

	while(ptr)
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
}