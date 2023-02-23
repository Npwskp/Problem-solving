#include <bits/stdc++.h>
using namespace std;

int n, w;
int cost[201], group[201];
vector<tuple<int, int, int>> mst;
int check = 0;
int psize[201];
int total_weight = 0;

int find(int u)
{
    if (group[u] == u)
        return u;
    return group[u] = find(group[u]);
}

void union_set(int u, int v)
{
    if (psize[v] > psize[u])
    {
        swap(u, v);
    }
    group[u] = v;
    psize[u] += psize[v];
}

void insertM(tuple<int,int,int> xx){
    int i = 0;
    int c,u,v;
    tie(c,u,v) = xx;
    while(i < mst.size()){
        //cout << "hi" << "\n";
        if(c < get<0>(mst[i])){
            mst.insert(mst.begin()+i,xx);
            return;
        }
        i++;
    }
    mst.insert(mst.end(),xx);
}

int main()
{
    cin >> n >> w;
    for (int i = 0; i < w; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        if(i == 0) mst.push_back({c, u, v});
        else insertM({c, u, v});

        total_weight = 0;
        for (int xx = 1; xx <= n; xx++)
        {
            group[xx] = xx;
            psize[xx] = 0;
        }
        int count = 0;
        for (int j = 0; j < mst.size(); j++)
        {
            if (count == n - 1)
                break;
            int weight, x, y;
            tie(weight, x, y) = mst[j];
            int prx = find(x);
            int pry = find(y);
            if (prx != pry)
            {
                count++;
                union_set(prx, pry);
                total_weight += weight;
            }
            //cout << x << " " << y << " " << weight << " " << j << " " << "\n";
            // cout << prx << " " << pry << "\n";
        }
        if (count < n-1) cout << -1 << "\n";
        else cout << total_weight << "\n";
    }
}