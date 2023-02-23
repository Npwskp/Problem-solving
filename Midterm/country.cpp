#include <bits/stdc++.h>
using namespace std;

int r,c,a,b,x,y;
int country[100][100];
int min_visa = 999999;
int visited[100][100];

int main(){
    cin >> r >> c >> a >> b >> x >> y ;
    a--;b--;x--;y--;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int tmp;
            cin >> tmp;
            country[i][j] = tmp;
        }
    }

    set<tuple<int,int,int>> q;
    q.insert({0,a,b});
    int destination = country[x][y];
    //cout << "destination " << destination << "\n";
    while(!q.empty()){
        tuple<int,int,int> vertex = *q.begin();
        q.erase(q.begin());
        int zz = get<0>(vertex),xx = get<1>(vertex),yy = get<2>(vertex);
        if(visited[xx][yy]) continue;
        visited[xx][yy] = 1;
        //cout << xx << " " << yy << " " << zz << " " << country[xx][yy] << "\n";
        if(country[xx][yy] == destination){
            if(zz < min_visa){
                min_visa = zz;
            }
        }
        if(xx-1 >= 0){
            if(country[xx-1][yy] != country[xx][yy])
                q.insert({zz+1,xx-1,yy});
            else q.insert({zz,xx-1,yy});
        }
        if(xx+1 < r){
            if(country[xx+1][yy] != country[xx][yy])
                q.insert({zz+1,xx+1,yy});
            else q.insert({zz,xx+1,yy});
        }
        if(yy-1 >= 0){
            if(country[xx][yy-1] != country[xx][yy])
                q.insert({zz+1,xx,yy-1});
            else q.insert({zz,xx,yy-1});
        }
        if(yy+1 < c){
            if(country[xx][yy+1] != country[xx][yy])
                q.insert({zz+1,xx,yy+1});
            else q.insert({zz,xx,yy+1});
        }

    }

    cout << min_visa;
}