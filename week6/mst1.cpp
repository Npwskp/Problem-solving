#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<tuple<int,int,int>> mst;
int group[1005];
int total_weight = 0;

int find(int u){
    return group[u];
}

void union_set(int u, int v){
    u = group[u];
    v = group[v];
    for(int i=1;i<=n;i++){
        if(group[i] == u) group[i] = v;
    }
}

int main(){
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        group[i] = i;
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        mst.push_back({c,a,b});
    }
    sort(mst.begin(),mst.end());

    for(int i=0;i<n;i++){
        int weight = get<0>(mst[i]);
        int x = get<1>(mst[i]);
        int y = get<2>(mst[i]);
        if(find(x) != find(y)){
            union_set(x,y);
            total_weight += weight;
        }
    }

    cout << total_weight;
}