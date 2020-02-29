#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	for (int i = 0; i < 4; ++i)
	{
		int number = 4 - i;
		cout << setw(number) << "*";
		for (int j = 0; j < i * 2; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 0; i < 3; ++i)
	{
		int number = i + 2;
		cout << setw(number) << "*";
		for (int j = 0; j < 4 - i * 2; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}