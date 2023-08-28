#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector <pair<int, int>> adj[N];

int dis[N];

void dijkstra(int s){
    queue<int> q;
    dis[s] = 0;

    while(!q.empty()){ 
        int par = q.front();
        q.pop();
        for(int i = 0; i < adj[par].size(); i++){
            pair<int, int> pr = adj[par][i];
            int child = pr.first;
            int cost = pr.second;

            if(dis[par] + cost < dis[child]){
                dis[child] = dis[par] + cost;
                q.push(child);
            }
        }
    }

}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        
    }

    for(int i = 0; i < n; i++){
        dis[i] = INT_MAX;
    }

    dijkstra(1);

    return 0;
}