#include "bits/stdc++.h"
using namespace std;

int t[1001][1001];

int pattern_matching_lcs(string X, string Y, int m, int n)
{
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1])
				t[i][j] = t[i - 1][j - 1] + 1;
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}

	return t[m][n];
}

int main()
{
	string X = "axy", Y = "adbxjly";
	int m = X.length(), n = Y.length();

	if (m == pattern_matching_lcs(X, Y, m, n))
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}