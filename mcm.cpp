#include "bits/stdc++.h"
using namespace std;

int main()
{
	// vector<vector<int>> t = {
	// 	{12, 3, 1},
	// 	{5, 2, 10},
	// 	{234, 876, 9}
	// };

	// for (int i = 0; i < t.size(); i++)
	// {
	// 	for (int j = 0; j < t[i].size(); j++)
	// 		cout << t[i][j] << " ";

	// 	cout << "\n";
	// }

	// t.clear();
	// int n = 4, m = 5;
	// vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

	// for (int i = 0; i < dp.size(); i++)
	// {
	// 	for (int j = 0; j < dp[i].size(); j++)
	// 		cout << dp[i][j] << " ";

	// 	cout << endl;
	// }

	// dp.clear();

	int n = 1001, m = 1001;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
			cout << dp[i][j] << " ";

		cout << "\n";
	}
	dp.clear();
	return 0;
}