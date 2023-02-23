#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b, x, y, minn = 999999;
char arr[60][60];
vector<pair<int, int>> dirt;

int Min(int a,int b){
    return a < b ? a : b;
}

int bfs()
{
    int visited[60][60] = {0};

    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    while (!q.empty())
    {
        pair<int, int> vertex = q.front();
        q.pop();
        int xx = vertex.first;
        int yy = vertex.second;
        // cout << xx << " " << yy << " " << arr[xx][yy] << "\n";
        if (xx == x && yy == y)
        {
            return visited[x][y] - 1;
        }
        if (arr[xx][yy] == '#' || arr[xx][yy] == '*')
            continue;

        if (yy != m && visited[xx][yy + 1] == 0 && arr[xx][yy + 1] != '|' && arr[xx][yy] != '|')
        {
            q.push({xx, yy + 1});
            visited[xx][yy + 1] = visited[xx][yy] + 1;
        }

        if (yy != 0 && visited[xx][yy - 1] == 0 && arr[xx][yy - 1] != '|' && arr[xx][yy] != '|')
        {
            q.push({xx, yy - 1});
            visited[xx][yy - 1] = visited[xx][yy] + 1;
        }

        if (xx != n && visited[xx + 1][yy] == 0 && arr[xx + 1][yy] != '-' && arr[xx][yy] != '-')
        {
            q.push({xx + 1, yy});
            visited[xx + 1][yy] = visited[xx][yy] + 1;
        }

        if (xx != 1 && visited[xx - 1][yy] == 0 && arr[xx - 1][yy] != '-' && arr[xx][yy] != '-')
        {
            q.push({xx - 1, yy});
            visited[xx - 1][yy] = visited[xx][yy] + 1;
        }
    }
    return 999999;
}

int main()
{
    cin >> n >> m;
    cin >> a >> b >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp;
            if (tmp == '*')
                dirt.push_back({i, j});
        }
    }

    minn = Min(minn,bfs());

    for (int i = 0; i < dirt.size(); i++)
    {
        int c1 = dirt[i].first, c2 = dirt[i].second;
        arr[c1][c2] = '|';
        minn = Min(minn,bfs());
        arr[c1][c2] = '-';
        minn = Min(minn,bfs());
        arr[c1][c2] = '*';
    }
    if (minn == 999999)
        cout << -1;
    else
        cout << minn;
}