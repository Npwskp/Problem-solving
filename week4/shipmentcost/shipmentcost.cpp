#include <bits/stdc++.h>
using namespace std;

int N,M,S,T;
vector<int> adj[100005];
queue<int> start;
int visited[100005] = {0}; // ให้ค่า visit ทั้งหมดเป็น 0

int main(){
    cin >> N >> M >> S >> T;
    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //เนื่องจากต้องตอบเป็นโรงงาน จึงเริ่มที่คลังสินค้าเลย
    for(int i=0;i<S;i++){ 
        int tmp;
        cin >> tmp;
        visited[tmp] = 1;
        start.push(tmp); // visited 1 push เข้า queue
    }
    while(!start.empty()){ //เริ่มจากคลังสินค้าทั้งหมดก่อน
        int xx = start.front();
        start.pop();
        for(int i=0;i<adj[xx].size();i++){
            int next = adj[xx][i];
            if(visited[next] == 0){
                visited[next] = visited[xx]+1; // visited เป็นค่าของ parent ที่ + เรื่อยๆ
                start.push(next);
            }
        }
    }
    for(int i=0;i<T;i++){
        int tmp;
        cin >> tmp;
        cout << visited[tmp]-1 << "\n"; //ตอบ visited-1 เพราะเริ่มจากคลังสินค้าเป็น 0
    }
}