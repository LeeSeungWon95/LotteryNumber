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
		// i번째 값이 제일 좋은 후보라고 가정
		int Best = i;

		// 다른 후보와 비교를 통해 제일 좋은 후보를 찾아나선다
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
	// 랜덤으로 1~45의 숫자를 6개 골라서 정렬(중복 없이)
	srand((unsigned)time(NULL));
	
	int Count = 0;
	while (Count != 6)
	{
		int RandValue = (rand() % 45) + 1;

		// 이미 찾은 값인지?
		bool Found = false;
		for (int i = 0; i < Count; i++)
		{
			// 이미 찾은 값
			if (Numbers[i] == RandValue)
			{
				Found = true;
				break;
			}
		}

		// 못찾았으면 추가
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