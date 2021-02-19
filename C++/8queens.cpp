#include <iostream>
using namespace std;

/*完全使用Programming in lua的思路 C++实现*/

static int N = 8;
static int arr[8] = {0};

bool IsPlaceOK(int row, int column)
{
	for (int i = 0; i < row; ++i)
	{
		if ((arr[i] == column) ||
			((arr[i] - i) == (column - row)) ||
			((arr[i] + i) == (column + row)))
		{
			return false;
		}
	}
	return true;
}

void PrintSolution()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << (arr[i] == j ? "*" : "-");
		}
		cout << endl;
	}
	cout << "=============" << endl;
}

void AddQueen(int row)
{
	if (row >= N)
	{
		PrintSolution();
	}
	else
	{
		for (int column = 0; column < N; ++column)
		{
			if (IsPlaceOK(row, column))
			{
				arr[row] = column;
				AddQueen(row + 1);
			}
		}
	}
}

int main()
{
	AddQueen(0);

	system("pause");
	return 0;
}