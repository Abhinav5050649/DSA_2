#include "bits/stdc++.h"
using  namespace std;

//Coin Change --> Minimum Number of Coins
int t[4][6];

int min_CC(int coin[], int n, int sum)
{
	for (int i= 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			if (i == 0)
			{
				t[0][j] = INT_MAX - 1;
			}
			else if (j == 0)
			{
				t[i][0] = 0;
			}
			else if (i == 1)
			{
				if (j%coin[0] == 0)
				{
					t[i][j] = j/coin[0];
				}
				else
				{
					t[i][j] = INT_MAX - 1;
				}
			}
		}
	}

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (coin[i - 1] <= j)
			{
				t[i][j] = min(1 + t[i][j - coin[i - 1]], t[i - 1][j]);
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
	int n = 3, sum = 5;
	cout << min_CC(coin, n, sum) << endl;
	return 0;
}