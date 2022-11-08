#include "bits/stdc++.h"
using namespace std;

int t[5][5];

void init_t()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
				t[i][j] = 0;
			if (i == 0)
				t[i][j] = 1;
		}
	}
}

int sub_sum(int arr[], int n, int s1)
{
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			if (arr[i - 1] <= j)
			{
				t[i][j] = t[i- 1][j - arr[i - 1]] + t[i -  1][j];
			}
			else
			{
				t[i][j] = t[i - 1][j];
			}
		}
	}
	return t[n][s1];
}

int main()
{
	int arr[] = {1, 1, 2, 3};
	int n = 4, sum =1, sum_of_arr= 7;
	int s1 = sum + sum_of_arr/2;
	init_t();
	cout << sub_sum(arr, n, s1) << endl;
	return 0;
}