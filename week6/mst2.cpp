#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<tuple<int,int,int>> mst;
int group[100005];
int psize[100005];
int total_weight = 0;

int find(int u)
{
  if(group[u] == u) return u;
  return group[u] = find(group[u]);
}

void union_set(int u, int v){
    if(psize[v] > psize[u]){
        swap(u,v);
    }
    group[u] = v;
    psize[u] += psize[v];
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

    for(int i=0;i<m;i++){
        int weight,x,y;
        tie(weight,x,y) = mst[i];
        int prx = find(x);
        int pry = find(y);
        if(prx != pry){
            union_set(prx,pry);
            total_weight += weight;
        }
    }

    cout << total_weight;
}