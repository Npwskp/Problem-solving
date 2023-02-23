#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> adj[100005];
int dist[100005];
int visited[100005];
set<pair<int,int>> q;

int checkend(){
    for(int i=1;i<=n;i++){
        if(dist[i] == 999999)
            return 0;
    }
    return 1;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        dist[i]=999999;
        visited[i] = 0;
    }
    dist[1]=0;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    q.insert({0,1});
    while(!q.empty()){
        pair<int,int> node = *(q.begin());
        int distant = node.first;
        int vect = node.second;
        visited[vect] = 1;
        //cout << "Main node : " << vect << "  " << dist << "\n";
        if(distant < dist[vect])
            dist[vect] = distant;
        //cout << "Child node : \n";
        for(int i=0;i<adj[vect].size();i++){
            pair<int,int> next_node = adj[vect][i];
            if(visited[next_node.first]) continue;
            int new_dist = distant+(next_node).second;
            q.insert({new_dist,next_node.first});
            //cout << next_node.first << "  " << new_dist << "\n";
        }
        if(checkend())
            break;
        q.erase(q.begin());
    }
    cout << dist[n];
}