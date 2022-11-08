#include "bits/stdc++.h"
using namespace std;

// void knap(int wt[], int val[], int n, int W, int profit, vector<int> &ds)
// {
//     if (n == 0 | W == 0)
//     {
//         ds.push_back(profit);
//         return;
//     }

//     if (wt[n - 1] <= W)
//     {
//         knap(wt, val, n - 1, W - wt[n - 1], profit + val[n - 1], ds);
//         knap(wt, val, n - 1, W, profit, ds);
//     }
//     else
//     {
//         knap(wt, val, n - 1, W, profit, ds);
//     }
// }

int knap(int wt[], int val[], int n, int W)
{
    if (n == 0 || W == 0)
        return 0;
    
    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knap(wt, val, n - 1, W - wt[n - 1]), knap(wt, val, n - 1, W));
    }
    else
    {
        return knap(wt, val, n - 1, W);
    }
}

int main()
{   
    int n = 4, W = 10, profit = 0;
    //vector<int> ds;
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};

    profit = knap(wt, val, n, W);
    cout << profit << endl;
    // sort(ds.begin(), ds.end());
    // cout << ds[ds.size() - 1] << endl;
    // ds.clear();
    return 0;
}