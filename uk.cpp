#include "bits/stdc++.h"
using namespace std;

int t[5][8];
//Unbounded Knapsack Problem
void init_t()
{
	for (int i = 0; i< 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}
}

int uknap(int wt[], int val[], int n, int W)
{
	for (int i = 1; i< n+1; i++)
	{
		for (int j = 1; j< W + 1; j++)
		{
			if (wt[i - 1] <= j)
			{
				t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);

			}
			else
			{
				t[i][j] = t[i - 1][j];
			}
		}
	}
	return t[n][W];
}

int main()
{
	int wt[] = {1, 3, 4, 5};
	int val[] = {1, 4, 5, 7};
	int n = 4, W = 7;
	cout << uknap(wt, val, n, W) << endl;
	return 0;
}