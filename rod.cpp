#include "bits/stdc++.h"
using namespace std;

//Rod Cutting Problem
//Please use solution used in GFG Problem. This one is not the GFG solution
//Do look at the commmented code(s) below the main function

int t[9][9];
void init_t()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
}

int ruknap(int pr[], int len[], int n, int W)
{
	init_t();
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < W + 1; j++)
		{
			if (len[i - 1] <= j)
			{
				t[i][j] = max(pr[i - 1] + t[i][j - len[i - 1]], t[i - 1][j]);
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
	int len[] = {1, 2, 3, 4, 5, 6, 7, 8}, pr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = 8, W = 8;

	cout << ruknap(pr, len, n, W) << endl;
	return 0;
}

/*
Other Methods:-->

#include "bits/stdc++.h"
using namespace std;

int t[9][9];

// int rod(int pr[], int len[], int n, int net_len)
// {
// 	for (int i = 0; i < n + 1; i++)
// 	{
// 		for (int j = 0; j < net_len + 1; j++)
// 		{
// 			if (i == 0 || j== 0)
// 			{
// 				t[i][j] = 0;
// 			}
// 		}
// 	}

// 	for (int i = 1; i < n + 1; i++)
// 	{
// 		for (int j = 1; j < net_len + 1; j++)
// 		{
// 			if (len[i - 1] <= j)
// 			{
// 				t[i][j] = max(pr[i - 1] + t[i][j - len[i - 1]], t[i - 1][j]);
// 			}
// 			else
// 			{
// 				t[i][j] = t[i - 1][j];
// 			}
// 		}
// 	}

// 	return t[n][net_len];
// }

int rod(int pr[], int n, int W)
{
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < W + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < W + 1; j++)
		{
			if (i <= j)
			{
				t[i][j] = max(pr[i - 1] + t[i][j - i], t[i - 1][j]);
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
	int pr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int len[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = 8, net_len = 8;

	cout << rod(pr, n, net_len) << endl;
	return 0;
}
*/