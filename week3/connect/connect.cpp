#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int degree[100005];
int visited[100005];

void dfs(int u){
    visited[u] = 1;
    for(int i=0; i<degree[u]; i++){
        int v = adj[u][i];
        if(visited[v] == 0){
        dfs(v);
        }
    } 
}

int checkvisit(int visited[100005],int n){
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            return i;
        }
    }
    return -1;
}

int main(){ //dfs จนหมด = connect หา node ใหม่คิดต่อ
    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    for(int i=0;i<n;i++)
        visited[i] = 0;

    int count = 0;
    while(1){
        int enable = checkvisit(visited,n);
        if(enable == -1){
            break;
        }
        dfs(enable);
        count++;
    }
    cout << count ;
}