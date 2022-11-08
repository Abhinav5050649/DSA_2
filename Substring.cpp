#include "bits/stdc++.h"
using namespace std;

int t[1001][1001];
//Longest Common Substring
int lcSub(string X, string Y, int m, int n)
{
	int result = 0;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1])
			{
				t[i][j] = 1 + t[i - 1][j - 1];
				result = max(result, t[i][j]);
			}
			else
			{
				t[i][j] = 0;
			}
		}
	}

	return result;
}

int main()
{
	string X = "abdhj", Y = "abehj";
	int m = X.length(), n = Y.length();

	cout << lcSub(X, Y, m, n) << endl;
	return 0;
}

/*
string X = "11011", Y = X;
	reverse(Y.begin(), Y.end());
	int m = X.length(), n = Y.length();

	int val  = lcSub(X, Y, m, n);
	int ans = (X.length() - val)/2;
	cout << ans << endl;
*/