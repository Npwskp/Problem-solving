#include<bits/stdc++.h>
using namespace std;

int distance(int dist[4]){
    int A = abs(dist[0]-dist[1]);
    int B = abs(dist[2]-dist[3]);
    return A*2+B*2;
}

int main(){
    string n;
    int k;
    cin >> n;
    cin >> k;
    int len = n.size(),count=0;
    int dist[4] = {0,0,0,0};
    for(int i=0;i<len;i++){
        if(n[i]=='N') dist[0]++;
        else if(n[i]=='S') dist[1]++;
        else if(n[i]=='E') dist[2]++;
        else if(n[i]=='W') dist[3]++;
    }
    /*for(int i=0;i<4;i++){
        cout << dist[i] << ' ';
    }
    cout << endl;*/
    for(int i=0;i<k;i++){
        if(!(dist[0] == 0 || dist[1] == 0)){
            if(dist[0] > dist[1]) dist[1]--;
            else dist[0]--;
        }
        else if(!(dist[2] == 0 || dist[3] == 0)){
            if(dist[2] > dist[3]) dist[3]--;
            else dist[2]--;
        }
        else{
            if(dist[0] != 0){
                dist[0]--;
                continue;
            }
            if(dist[1] != 0){
                dist[1]--;
                continue;
            }
            if(dist[2] != 0){
                dist[2]--;
                continue;
            }
            if(dist[3] != 0){
                dist[3]--;
                continue;
            }
        }
    }
    /*for(int i=0;i<4;i++){
        cout << dist[i] << ' ';
    }
    cout << endl;*/
    cout << distance(dist);
}

