#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[100005];
int degree[100005];
int visited[100005];
vector<int> ans;

int checkvisit(){
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            return i;
        }
    }
    return 0;
}

int main(){
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        degree[i] = 0;
        visited[i] = 0;
    }

    for(int i=0;i<m;i++){ //กราฟแบบไม่มีทิศทาง
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        degree[v]++; // เก็บดีกรีไว้ด้วยต้องเอาไปใช้ในการเช็ค source sink
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(degree[i] == 0){ // เลือก node dgree 0 เพราะ จะเป็น source
            q.push(i);
            //cout << i << '\n';
        }
    }
    if(q.empty()) // ถ้าไม่มีก็ทำ node 1 ไปก่อน
        q.push(1);
    int check = 0; // check ว่าเป็น topo มั้ย

    while(1){
        int cc = checkvisit(); // ทำcheckvisit เพราะ ต้องพยายามทำทุกตัวเท่าที่ทำได้
        if(q.empty() && cc != 0) // กรณีว่างแต่ไปต่อได้
            q.push(cc);
        else if(q.empty() && cc == 0) // กรณีไปต่อไม่ได้แล้ว
            break;

        int vert = q.front(); // bfs ปกติ
        q.pop();
        visited[vert] = 1;
        ans.push_back(vert); // ไส่ไปในคำตอบทุก node ที่ผ่านเข้ามา (การทำจะเรียงเสมออยู่แล้ว)
        for(auto xx=adj[vert].begin();xx!=adj[vert].end();xx++){
            int next = *xx; 
            if(visited[next] == 1){ //กรณีที่เกิด cycle , break ตอบ No
                check = 1;
                break;
            }
            degree[next]--; // ลบ dgree ทุกครั้งที่ไปหา node นั้นได้
            if(degree[next] == 0) // ใส่เข้า queue เมื่อเป็น deg = 0 เท่านั้น
                q.push(next);
        }
        if(check == 1) // เผิ่อหลุด เบรคอีกรอบ
            break;
    }

    //cout << check << '\n';
    if(check == 1) // check 1 ตอบ no
            cout << "no" ;
    else{
        for(auto xx=ans.begin();xx!=ans.end();xx++) //check 0 ตอบ ตาม ans vecter
            cout << *xx << '\n' ;
    }
}