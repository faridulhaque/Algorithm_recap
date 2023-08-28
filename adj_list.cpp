#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;

    vector<int> adj[n + 1];

    while (e--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    

    for (int i = 0; i < n; i++)
    {

        for (int v : adj[i]){
            cout<<v;
        }

        cout<<endl;
    }

    return 0;
}