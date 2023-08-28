#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, e;
    cin >> n >> e;

    int adj[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adj[i][j] = 0;
            if(i == j){
                adj[i][j] = 1;
            }
        }
    }

    while (e--)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }




    return 0;
}