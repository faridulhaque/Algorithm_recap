#include <bits/stdc++.h>
using namespace std;


const int N = 1e5+5;

int dist[N];
bool visited[N];
vector <int> adj[N];


void bfs(int src){
    queue<int> q;
    q.push(src);

    visited[src] = true;
    dist[src] = 0;

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(int i = 0; i < adj[parent].size(); i++){
            int child = adj[parent][i];

            if(visited[child]) continue;
            q.push(child);
            dist[child] = dist[parent] + 1;
            visited[child] = true;
        }
    }
    
}

int main()
{

    int n, e;

    cin>>n>>e;

    

    while(e--){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }


   bfs(1);

    return 0;
}