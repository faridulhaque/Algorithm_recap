#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int dist[N];
bool visited[N];
vector<int> adj[N];

void dfs(int s)
{

    visited[s] = true;

    for (int i = 0; i < adj[s].size(); i++)
    {
        int child = adj[s][i];

        if (visited[child])
            continue;
        dfs(child);
    }
}

int main()
{
    int n, e;

    cin >> n >> e;

    while (e--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
    }

    return 0;
}