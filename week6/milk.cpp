#include<bits/stdc++.h>
using namespace std;

int n,m;
int group[100005];
int psize[100005];

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        group[i] = i;
        psize[i] = 1;
    }

    for(int i=0;i<m;i++){
        char a;
        int b,c;
        cin >> a >> b >> c;
        int u = find(b);
        int v = find(c);
        if(a == 'q'){   
            if( u == v ) cout << "yes" << "\n";
            if( u != v) cout << "no" << "\n";
        }
        if(a == 'c'){
            union_set(u,v);
        }
    }
}