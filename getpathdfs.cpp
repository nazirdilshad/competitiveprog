#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
vector<int> *getpathhelper(int **edges, int v, int a, int b, bool *visited)
{
    if (a == b)
    {
        vector<int> *output = new vector<int>();
        output->push_back(b);
        return output;
    }
    visited[a] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[a][i] && !visited[i])
        {
            vector<int> *smalloutput = getpathhelper(edges, v, i, b, visited);
            if (smalloutput != NULL)
            {
                smalloutput->push_back(a);
                return smalloutput;
            }
        }
    }
    return NULL;
}

vector<int> *getpath(int **edges, int v, int a, int b)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    vector<int> *output = getpathhelper(edges, v, a, b, visited);
    delete[] visited;
    return output;
}

int main()
{
    int V, E;
    cin >> V >> E;
    int **edges = new int *[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            edges[i][j] = 0;
        }
    }
    int first, second;
    for (int i = 0; i < E; i++)
    {
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    //here first and second are starting and ending vertex
    cin >> first >> second;
    int visited[V + 1];
    memset(visited, 0, sizeof visited);

    vector<int> *output = getpath(edges, V, first, second);
    if (output != NULL)
    {
        for (int i = 0; i < output->size(); i++)
        {
            cout << output->at(i) << " ";
        }
    }

    

    return 0;
}
