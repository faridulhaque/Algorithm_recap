#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

const int N = 1005;

int n, m;

bool visited[N][N];
int dis[N][N];

vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;

    return false;
}

void bfs(int si, int sj)
{
    queue<pi> q;

    q.push({si, sj});

    dis[si][sj] = 0;
    visited[si][sj] = true;

    while (!q.empty())
    {
        pi parent = q.front();
        q.pop();

        int p_i = parent.first;
        int p_j = parent.second;

        for (int i = 0; i < 4; i++)
        {
            pi p = path[i];

            int ci = p_i + p.first;
            int cj = p_j + p.second;

            if (isValid(ci, cj) && !visited[ci][cj])
            {
                visited[ci][cj] = true;
                q.push({ci, cj});
                dis[ci][cj] = dis[p_i][p_j] + 1;
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    char a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int sI, sJ;
    cin >> sI >> sJ;

    bfs(sI, sJ);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dis[i][j];
        }
    }

    return 0;
}