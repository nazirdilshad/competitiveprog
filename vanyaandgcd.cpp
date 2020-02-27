#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v420;

#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define maxi 100000
#define pii pair<int, int>
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define mem(x, y) memset(x, y, sizeof(x))
#define DANGER                        \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

long mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    ll dp[n + 1][101] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x = a[0];
    dp[0][x] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i][a[i]] = ((dp[i][a[i]] % mod) + 1) % mod;
        for (int k = i - 1; k >= 0; k--)
        {
            if (a[i] <= a[k])
            {
                continue;
            }
            else
            {
                for (int j = 1; j <= 100; j++)
                {
                    int ng = __gcd(a[i], j);
                    dp[i][ng] = ((dp[i][ng]) % mod + (dp[k][j]) % mod) % mod;

                    
                }
            }
        }
    }
    
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = ((sum % mod) + (dp[i][1]) % mod) % mod;
    }
    cout << sum;
}