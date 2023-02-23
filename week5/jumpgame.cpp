#include<bits/stdc++.h>
using namespace std;

int arr[21][21];
int visited[21][21];
int n,k;

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }
    

    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        int x = node.first,y = node.second;
        //if(arr[x][y] == 15) cout << arr[x][y] << arr[x][y+1] << "\n";
        if(visited[x][y]) continue;
        if(x==n-1 && y==n-1){
            cout << "yes";
            return 0;
        }
        if(x-1 >= 0){
            if((arr[x-1][y]-arr[x][y]) <=k)
                q.push({x-1,y});
        }
        if(x+1 < n){
            if((arr[x+1][y]-arr[x][y]) <=k)
                q.push({x+1,y});
        }
        if(y-1 >= 0){
            if((arr[x][y-1]-arr[x][y]) <=k)
                q.push({x,y-1});
        }
        if(y+1 < n){
            if((arr[x][y+1]-arr[x][y]) <=k)
                q.push({x,y+1});
        }
        visited[x][y] = 1;
    }
    cout << "no";
}
