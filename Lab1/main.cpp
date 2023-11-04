#include"Header.h"

int main()
{
	const char* filename = "f.txt";
	int size = 0;

	if (FilePrint(filename) < 1)
	{
		puts("Continue impossible!");
		return 1;
	}
	STACK* p = LoadFileToStack(filename,size);

	PrintStack(p);
	renumber(p,size);
	purge(p);

	PrintStack(p);

	puts("END OF PROGRAM!\n");

	return 0;
}