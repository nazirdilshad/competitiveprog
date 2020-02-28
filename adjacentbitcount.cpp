
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

ll dp[101][101][2];
ll mod = 1e9 + 7;

int adjacentbitcount(int n, int k, int first)
{
    if (n == 0)
    {
        if (!k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (k < 0)
    {
        return 0;
    }
    ll x, y, w1 = 0, w2 = 0, w3 = 0, w4 = 0;
    if (first == 0)
    {
        if (dp[n][k][first] == -1)
        {
            dp[n][k][first] = ((adjacentbitcount(n - 1, k, 1)) % mod + (adjacentbitcount(n - 1, k, 0)) % mod) % mod;
        }

        return dp[n][k][first];
    }
    if (first == 1)
    {
        if (dp[n][k][first] == -1)
            dp[n][k][first] = ((adjacentbitcount(n - 1, k, 0)) % mod + (adjacentbitcount(n - 1, k - 1, 1)) % mod) % mod;

        return dp[n][k][first];
    }
}

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;

    memset(dp, -1, sizeof(dp));
    ll sum = adjacentbitcount(y - 1, z, 0);
    ll sum2 = adjacentbitcount(y - 1, z, 1);
    cout << x << " " << ((sum + sum2) % mod) << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
}