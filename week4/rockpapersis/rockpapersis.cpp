#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[100005];
vector<pair<int,int>> edge;
//int visited[1005] = {0};

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back({u,v});
    }

    for(int i=0;i<m;i++){
        pair<int,int> node = edge[i];
        int bipar[100005] = {0};
        queue<int> q;
        int check = 0;
        int vertex = 1;
        for(int ii=0;ii<2;ii++){
            if(vertex == node.first || vertex == node.second)
                vertex++;
            else    
                break;
        }
        q.push(vertex);
        bipar[vertex] = 1;
        while(!q.empty()){
            int vert = q.front();
            q.pop();
            for(int xx=0;xx<adj[vert].size();xx++){
                int next = adj[vert][xx];
                if((next == node.first && vert == node.second) || (next == node.second && vert == node.first)){
                    continue;
                }
                if(bipar[next] == 0) 
                    q.push(next);
                if(bipar[next] == 0) 
                    bipar[next] = -1*bipar[vert];
                else if(bipar[vert] == bipar[next]){
                    check = 1; 
                    break;
                }
            }
            if(check)
                break;
        }
        if(!check){
            cout << node.first << " " << node.second;
            break;
        }

    }
}