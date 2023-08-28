#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<pair<int, int>> adj[N];
bool visited[N];

int dis[N];

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    dis[s] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        if (visited[parentNode])
            continue;
        visited[parentNode] = true;
        int parentCost = parent.first;

        for (int i = 0; i < adj[parentNode].size(); i++)
        {
            pair<int, int> pr = adj[parentNode][i];
            int childNode = pr.first;
            int childCost = pr.second;

            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});

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
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(1);

    return 0;
}