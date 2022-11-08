#include "bits/stdc++.h"
using namespace std;

//Printing Longest Common Subsequence
int t[1001][1001];

string lcs(string X, string Y, int m, int n)
{
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (X[i - 1] = Y[j - 1])
			{
				t[i][j] = t[i - 1][j - 1] + 1;
			}
			else
			{
				t[i][j] = max(t[i - 1][j], t[i][j -1]);
			}
		}
	}

	string ans = "";
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		if (X[i - 1] == Y[j - 1])
		{
			ans.push_back(X[i - 1]);
			i--, j--;
		}
		else
		{
			if (t[i][j - 1] > t[i - 1][j])
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}
	// }
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	string X = "abedgh", Y = "abdefghr";
	int m = X.length(), n = Y.length();
	cout << lcs(X, Y, m, n) << endl;
	return 0;
}