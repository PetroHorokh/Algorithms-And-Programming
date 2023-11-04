#include"Header.h"

int main()
{
	CASAFUNCTIONS* Array;

	int len;

	CASA** arr = CreatArray(len);

	for (int i = 0; i < len; i++)
	{
		cout << *arr[i] << endl;
	}

	DeleteArray2D(arr, len);

	cout << "End of program!" << endl;

	return 0;
}