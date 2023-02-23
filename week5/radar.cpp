#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> dist;
int casee = 0;

int dist_c(int y){
    return sqrt(m*m-y*y);
}

int radar(){
    int countt = 0;
    sort(dist.begin(),dist.end());
    for(int i=0;i<n;i++){
        countt++;  
        int j;
        for(j=i+1;j<n;j++){
            if(dist[i].second >= dist[j].first){
                if(dist[i].second >= dist[j].second) i = j;
            }
            else{
                i = j-1;
                break;
            }
        }
        if(j == n) break;
    }
    return countt;
}

int main(){
    while(1){
        int check = 0;
        casee++;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i=0;i<n;i++){
            int x,y;
            cin >> x >> y;
            if(y>m) check = 1;
            dist.push_back({x-dist_c(y),x+dist_c(y)});
        }

        if(check) cout << "Case " << casee << ": " << -1 << "\n";
        else cout << "Case " << casee << ": " << radar() << "\n";
        dist.clear();
    }
}