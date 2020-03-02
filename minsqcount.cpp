#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int getMinSquares(int n)
{
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;

    if (n <= 3 || dp[n] != -1)
        return dp[n];

    int xx = n;
    for (int x = 1; x * x <= n; x++)
    {
        int temp = x * x;
        if (temp > n)
            break;
        else
        {
            xx = min(xx, 1 + getMinSquares(n - temp));
        }
    }
    return dp[n] = xx;
}

int minCount(int n)
{

    memset(dp, -1, sizeof dp);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    return getMinSquares(n);
}
int main()
{
    int n;
    cin >> n;

    cout << minCount(n);
}