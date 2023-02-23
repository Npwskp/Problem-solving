#include <bits/stdc++.h>
using namespace std;

int N,R;
int dist[1005];
vector<int> ans;
vector<int> graph[1005];
vector<vector<int>> node;

int distance(vector<int> x,vector<int> y){
    return (x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1]);
}

int findpath(){
    int count=0,goal=N+1;
    for(int i=0;i<N+2;i++) dist[i]=0;
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0;i<graph[v].size();i++){
            int tmp = graph[v][i];
            if(tmp == goal)
                return dist[v]+1;
            if(dist[tmp])
                continue;
            q.push(tmp);
            dist[tmp]=dist[v]+1;
        }
    }
    return -1;
}

int main(){
    cin >> N >> R;
    node.push_back({0,0});
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        node.push_back({x,y});
    }
    node.push_back({100,100});

    for(int i=0;i<N+2;i++){
        for(int j=i+1;j<N+2;j++){
            if(distance(node[i],node[j]) <= R*R){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    /*if(findpath() == -1 && ans.size() == 0)
        cout << -1;
    else
        cout << *min_element(ans.begin(),ans.end());*/
    cout << findpath();
}