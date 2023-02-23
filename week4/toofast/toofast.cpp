#include <bits/stdc++.h>
using namespace std;

int n,m,check = 0,max_cost = -1;
vector<tuple<int,int,int>> adj[1005];
int visited[1005][2];
set<tuple<int,int,int>> q; //0 = cost, 1 = check ,2 = next
set<tuple<int,int>> ans;


int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c,s;
        cin >> a >> b >> c >> s;
        adj[a].push_back({b,c,s});
        adj[b].push_back({a,c,s});
    }

    for(int i=1;i<=n;i++) {
        visited[i][0] = 999999;
        visited[i][1] = 999999;
    }
    visited[1][0] = 0;
    visited[1][1] = 0;
    q.insert({0,1,0});
    while(!q.empty()){
        tuple<int,int,int> vertex = *q.begin();
        q.erase(q.begin());
        int cost = get<0>(vertex);
        int node = get<1>(vertex);
        int check = get<2>(vertex);
        //cout << "Main node : " << node << " Cost : " << cost << " Check : " << check << "\n";
        for(int i=0;i<adj[node].size();i++){
            tuple<int,int,int> next_v = adj[node][i];
            int next_node = get<0>(next_v);
            int plus = get<1>(next_v);
            int s = get<2>(next_v);
            //cout << "Child node : " << next_node << " Cost : " << plus << " Check : " << s << "\n";
            if(check+s > 1) continue;
            if(cost+plus < visited[next_node][check+s]){
                visited[next_node][check+s] = cost+plus;
                q.insert({cost+plus,next_node,check+s});
            }
        }
        
    }
    if(visited[n][0] == 999999 && visited[n][1] == 999999) cout << -1 ;
    else cout << min(visited[n][0],visited[n][1]);   
}

