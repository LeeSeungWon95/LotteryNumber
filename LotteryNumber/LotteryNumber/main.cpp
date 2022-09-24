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
{		// { 15, 7, 45, 10, 29, 31 } -> { 7, 10, 15, 29, 31, 45 }
	for (int i = 0; i < Count; i++)
	{
		// i��° ���� ���� ���� �ĺ���� ����
		int Best = i;

		// �ٸ� �ĺ��� �񱳸� ���� ���� ���� �ĺ��� ã�Ƴ�����
		for (int j = i + 1; j < Count; j++)
		{
			if (Numbers[j] < Numbers[Best])
			{
				Best = j;
			}
		}

		if (i != Best)
		{
			Swap(Numbers[i], Numbers[Best]);
		}
	}
}

int main()
{
	int Number1 = 1;
	int Number2 = 3;
	Swap(Number1, Number2);

	int Numbers[] = { 15, 7, 45, 10, 29, 31 };
	Sort(Numbers, sizeof(Numbers) / sizeof(int));

	return 0;
}