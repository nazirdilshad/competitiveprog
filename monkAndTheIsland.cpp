#include <bits/stdc++.h>
using namespace std;
vector<int> edges[1000006];
int visited[100006];


void solve()
{
    int v, e;
    cin >> v >> e;
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    
    int level[v + 1];
    memset(level, 0, sizeof level);
    queue<int> q;
    q.push(0);
    int x = 0;
    level[0] = x;
    visited[0] = 1;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        //x++;
        for (int i = 0; i < edges[element].size(); i++)
        {
            int adjacent = edges[element][i];

            if (!visited[adjacent])
            {
                q.push(adjacent);
                visited[adjacent] = 1;
                level[adjacent] = level[element] + 1;
                if (adjacent == v - 1)
                {
                    break;
                }
            }
        }
    }

    cout << level[v - 1] << endl;
    
    for (int i = 0; i < 1000006; i++)
    {
        edges[i].clear();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
