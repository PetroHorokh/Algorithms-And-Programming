#include"Header.h"

int main()
{

	NUMERATOR a;

	a.CreatArray();

	a.OutputCasaArray("\nArray before changes\n");

	a.Numerise();

	a.OutputCasaArray("\nArray before sort\n");

	a.Sort();

	a.OutputCasaArray("\nArray after sort\n");

	a.DeleteArray2D();

	cout << "End of program!" << endl;

	return 0;
}