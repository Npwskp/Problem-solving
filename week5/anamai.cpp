#include<bits/stdc++.h>
using namespace std;

int n,m,k,maxx = 0;
vector<int> adj[100005];
int visited[100005];

void init_visit(){
    for(int i=1;i<=n;i++){
        visited[i] = 0;
    }
}

int main(){
    cin >>  n >> m >> k;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        //cout << "check " << i << "\n";
        init_visit();
        int count = 0;
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        //cout << "check 02 " << k << "\n";
        while(!q.empty()){
            int xx = q.front();
            q.pop();
            count++;
            //cout << xx << " " << visited[xx] << "\n";
            if(visited[xx] == k+1) continue;
            for(int j=0;j<adj[xx].size();j++){
                int vect = adj[xx][j];
                if(visited[vect] == 0){
                    q.push(vect);
                    visited[vect] = visited[xx]+1;
                }
            }
        }
        //cout << "Node" << i << " : "<< count << "\n" ;
        if(count > maxx) maxx = count;
    }
    cout << maxx;
}