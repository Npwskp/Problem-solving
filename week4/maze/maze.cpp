#include <bits/stdc++.h>
using namespace std;

int N,Q;
char adj[30][30];
vector<string> ans;

int main(){

    cin >> N >> Q;

    for(int i=1;i<=N;i++){
        string xx;
        cin >> xx;
        for(int j=0;j<N;j++){
            adj[i][j+1] = xx[j];
        }
    }

    for(int i=0;i<Q;i++){
        int sx,sy,ex,ey;
        cin >> sx >> sy >> ex >> ey;
        int visited[30][30] = {0};
        int status = 0;
        queue<tuple<int,int,int>> q;
        q.push({sx,sy,0});
        while(!q.empty()){
            tuple<int,int,int> vertex = q.front();
            q.pop();
            int x = get<0>(vertex),y = get<1>(vertex),z = get<2>(vertex);
            if( x<=0 || x>N || y<=0 || y>N) continue;
            if(adj[x][y] == '#') continue;
            if(x == ex && y == ey){
                status = 1;
                break;
            }
            if(adj[x][y] == 'O'){
                z+=1;
            }
            if(z>1) continue;
            //cout << x << " " << y << " " << z << " "<< adj[x][y] << "\n";
            if((adj[x][y] == '.' || adj[x][y] == 'O') && visited[x][y] == 0){
                q.push({x+1,y,z});
                q.push({x-1,y,z});
                q.push({x,y+1,z});
                q.push({x,y-1,z});
            }
            visited[x][y] = 1;
        }
        if(status == 1) ans.push_back("yes");
        else ans.push_back("no");
    }

    for(int i=0;i<Q;i++) cout << ans[i] << "\n";
}