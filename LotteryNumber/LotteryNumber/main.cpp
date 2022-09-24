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

void ChooseLotto(int* Numbers)
{
	// �������� 1~45�� ���ڸ� 6�� ��� ����(�ߺ� ����)
	srand((unsigned)time(NULL));
	
	int Count = 0;
	while (Count != 6)
	{
		int RandValue = (rand() % 45) + 1;

		// �̹� ã�� ������?
		bool Found = false;
		for (int i = 0; i < Count; i++)
		{
			// �̹� ã�� ��
			if (Numbers[i] == RandValue)
			{
				Found = true;
				break;
			}
		}

		// ��ã������ �߰�
		if (Found == false)
		{
			Numbers[Count] = RandValue;
			Count++;
		}
	}

	Sort(Numbers, 6);

}


int main()
{
	int Number1 = 1;
	int Number2 = 3;
	Swap(Number1, Number2);

	int Numbers[] = { 15, 7, 45, 10, 29, 31 };
	Sort(Numbers, sizeof(Numbers) / sizeof(int));
	ChooseLotto(Numbers);

	for (int i = 0; i < 6; i++)
	{
		cout << Numbers[i] << endl;
	}

	return 0;
}