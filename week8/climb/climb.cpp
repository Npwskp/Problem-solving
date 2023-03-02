#include <bits/stdc++.h>
using namespace std;

int n,m,stx,sty,edx,edy;
char arr[31][31];
int visited[31][31];

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }

    queue<pair<int,int>> q;
    q.push({n-1,0});
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        int x,y;
        tie(x,y) = node;
        if(x == 0 && y == m-1){
            cout << visited[x][y];
            return 0;
        }
        if(arr[x][y] == 'X') continue;
        if(x+1 < n && visited[x+1][y] == 0){
            q.push({x+1,y});
            visited[x+1][y] = visited[x][y];
        }
        if(x-1 >= 0 && visited[x-1][y] == 0){
            q.push({x-1,y});
            visited[x-1][y] = visited[x][y]+5;
        }
        if(y-1 >= 0 && visited[x][y-1] == 0){
            q.push({x,y-1});
            visited[x][y-1] = visited[x][y]+1;
        }
        if(y+1 < m && visited[x][y+1] == 0){
            q.push({x,y+1});
            visited[x][y+1] = visited[x][y]+1;
        }
    }
    cout << -1;
}