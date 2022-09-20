#include <iostream>

using namespace std;

void Swap(int& Number1, int& Number2)
{
	int temp;
	temp = Number1;
	Number1 = Number2;
	Number2 = temp;
}

void Sort(int* Numbers, int Count)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < Count; i++)
	{
		for (k = 0; k < Count - 1 - j; k++)
		{
			if (Numbers[k] > Numbers[k + 1])
			{
				Swap(Numbers[k], Numbers[k + 1]);
			}
		}
		j++;
	}
}

int main()
{
	int Number1 = 1;
	int Number2 = 3;
	Swap(Number1, Number2);

	int Numbers[] = { 1, 7, 45, 10, 29, 31 };
	Sort(Numbers, sizeof(Numbers) / sizeof(int));

	for (int i = 0; i < sizeof(Numbers) / sizeof(int); i++)
	{
		cout << Numbers[i] << endl;
	}
	return 0;
}