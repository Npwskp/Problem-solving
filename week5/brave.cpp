#include<bits/stdc++.h>
using namespace std;

int n,m,k,h,count = 0;
vector<int> magic_v;
vector<pair<int,int>> adj[100005];
int visited[100005];

int main(){
    cin >> n >> m >> k >> h;
    int countt = 0;
    for(int i=0;i<k;i++){
        int tmp;
        cin >> tmp;
        magic_v.push_back(tmp);
    }

    for(int i=1;i<n;i++){
        visited[i] = 0;
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c}); //เก็บแบบ pair จะได้รู้ว่าทางนั้นไปได้มั้ย
        adj[b].push_back({a,c});
    }

    //main bfs
    queue<int> q;
    q.push(1);
    visited[1] = 1; // first node = 1
    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        countt+=1;
        if(visited[vertex] == h+1) continue; // of visited == h+1 แปลว่า ไปสุดได้แค่ layer นั้นๆแล้ว
        for(int i=0;i<adj[vertex].size();i++){
            int next = adj[vertex][i].first; // ตัวต่อไป
            int check = adj[vertex][i].second; // ตัวเช็ค
            if(visited[next] == 0 && check == 0){
                q.push(next);
                visited[next] = visited[vertex]+1; // normal bfs things
            }
        }
    }

    for(int i=0;i<k;i++){ // loop นี้ไล่ไปแต่ละ magic villege ถ้าอันไหน visited != 0 แสดงว่าเคยไป เรียก bfs
        int xx = magic_v[i];
        if(visited[xx] == 0) continue;
        //init_visit2(); // ทำvisted2 จะได้ให้มันไปทางเดิมได้แล้วรีค่าทุกๆรอบที่หมู่บ้านใหม่
        int visited2[100005] = {0};
        q.push(xx);
        visited2[xx] = visited[xx]; // ก้อปค่า visit ของหมู่บ้าน
        while(!q.empty()){
            int vertex = q.front();
            q.pop();

            if(visited[vertex] == 0 && visited2[vertex] != 0){ // ถ้าใน visited ไม่เคยไป แต่ visited2 ไป ให้ไปเพิ่มใน visitำก ด้วย
                visited[vertex] = visited2[vertex];
                countt+=1; // นับค่าบ้านที่ไปเพิ่ม
                }

            if(visited2[vertex] == h+1) continue; // bfs เดิม
            for(int i=0;i<adj[vertex].size();i++){
                int next = adj[vertex][i].first;
                int check = adj[vertex][i].second;
                if(visited2[next] == 0){
                    q.push(next);
                    visited2[next] = visited2[vertex]+1;                                                                                                                                
                }
            }
        }
    }
    cout << countt;
}