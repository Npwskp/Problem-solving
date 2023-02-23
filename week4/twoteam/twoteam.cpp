#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
int bipar[100005];
int group[100005];

int find(int u)
{
    if (group[u] == u)
        return u;
    return group[u] = find(group[u]);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        group[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (bipar[x] == 0)
        {
            if (bipar[y] != 0)
                bipar[x] = -1 * bipar[y];
            else
                bipar[x] = 1;
        }
        if (bipar[y] == 0)
        {
            if (bipar[x] != 0)
                bipar[y] = -1 * bipar[x];
            else
                bipar[y] = -1;
        }
        int u = find(x),v = find(y);
        if(group[u] != group[v]){
            group[u] = v;   
        }
        else if(group[u] == group[v]){
            if(bipar[x] == bipar[y]){
                cout << i;
                return 0;
            }
        } 
    }
}