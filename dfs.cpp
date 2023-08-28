#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];

bool visited [N];

void dfs(int s){

    visited[s] = true;

    for(int i = 0; i < adj[s].size();i++){
        int child = adj[s][i];

        if(visited[child]) continue;
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

    dfs(1);

    return 0;
}