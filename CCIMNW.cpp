#include "bits/stdc++.h"
using namespace std;

int t[4][6];
//

int cc(int coin[], int n, int sum)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i == 0)
			{
				t[0][j] = 0;
			}
			else if (j == 0)
			{
				t[i][0] = 1;
			}
			else if (coin[i - 1] <= j)
			{
				t[i][j] = t[i][j - coin[i-1]] + t[i-1][j];
			}
			else
			{
				t[i][j] = t[i - 1][j];
			}
		}
	}

	return t[n][sum];
}

int main()
{
	int coin[] = {1, 2, 3};
	int sum = 5;
	cout << cc(coin, 3, sum) << endl;
	return 0;
}