#include "bits/stdc++.h"
using namespace std;

bool t[6][12];

void init_t()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0;j < 12; j++)
		{
			if (j == 0)
				t[i][j] = false;
			if (i == 0)
				t[i][j] = true;
		}
	}
}

int knap(int arr[], int n, int target)
{
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < target + 1; j++)
		{
			if (arr[i - 1] <= target)
			{
				t[i][j] = (t[i- 1][j - arr[i - 1]] || t[i - 1][j]);
			}
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][target];
}

//Equal Sum Partition
int equal_sum(int arr[], int n, int target)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	if (sum % 2 != 0)
	{
		return 0;
	}
	else
	{
		return knap(arr, n, target);
	}
}

int main()
{
	init_t();
	int arr[] = {2, 3, 7, 8, 10};
	int n = 5, target = 11;
	
	cout << equal_sum(arr, n, target) << endl;
	return 0;
}