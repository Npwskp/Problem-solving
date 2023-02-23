#include<bits/stdc++.h>
using namespace std;

int n,m,k,h,maxx = 0;
vector<int> adj[100005];
int visited[100005];
int visited2[100005];
vector<int> place;
vector<pair<int,int>> anamai;

int main(){
    cin >> n >> m >> k >> h;
    for(int i=0;i<k;i++){
        int tmp;
        cin >> tmp;
        place.push_back(tmp);
    }
    for(int i=0;i<k;i++){
        int tmp;
        cin >> tmp;
        anamai.push_back({tmp,place[i]});
    }
    sort(anamai.begin(),anamai.end());

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<anamai.size();i++){
        int visited[100005] = {0};
        pair<int,int> start = anamai[i];
        int H = h;
        if(start.first == 1) H = H*2;
        int st = start.second;
        queue<int> q;
        q.push(st);
        visited[st] = 1;
        //cout << "H = " << H << "   st = "<< st <<"\n";
        while(!q.empty()){
            int xx = q.front();
            q.pop();
            if(visited2[xx] == 0 ){
                visited2[xx] = visited[xx];
                maxx++;
                //cout << xx << " " << visited2[xx] << "\n";
            }
            if(visited[xx] == H+1) continue;
            for(int j=0;j<adj[xx].size();j++){
                int vect = adj[xx][j];
                if(visited[vect] == 0){
                    q.push(vect);
                    visited[vect] = visited[xx]+1;
                }
            }
        }
    }
    cout << maxx;
}