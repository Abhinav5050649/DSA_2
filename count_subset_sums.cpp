#include "bits/stdc++.h"
using namespace std;

int t[7][11];

void init_t()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (j == 0)
				t[i][j] = 0;
			if (i == 0)
				t[i][j] = 1;
		}
	}
}

int knap(int arr[], int n, int sum)
{
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (arr[i  -1] <= j)
			{
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
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
	init_t();
	int arr[] = {2, 3, 5, 6, 8, 10};
	int n= 6, sum = 10;
	cout << knap(arr, n, sum) << endl;
	return 0;
}