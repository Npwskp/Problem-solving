#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> adj[100005];
int non_team[100005];
int bipar[100005];

int checkvisit(){
    for(int i=1;i<=n;i++){
        if(bipar[i] == 0 && non_team[i] == 0){
            return i;
        }
    }
    return 0;
}

int main(){
    cin >> n >> m >> k;
    int st_node = 1;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(adj[u].size() >= k)
            non_team[u] = 1;
        else st_node = u;
        if(adj[v].size() >= k)
            non_team[v] = 1;
        else st_node = v;
    }

    queue<int> vertex;
    vertex.push(st_node); //  เริ่มที่ node 1 ใส่ค่า bipar
    bipar[st_node] = 1;
    int check = 0;
    while(1){ //ทำ bfs

        int cc = checkvisit(); // ทำcheckvisit เพราะ ต้องพยายามทำทุกตัวเท่าที่ทำได้
        if(vertex.empty() && cc != 0){ // กรณีว่างแต่ไปต่อได้
            vertex.push(cc);
            bipar[cc] = 1;
            }
        else if(vertex.empty() && cc == 0) // กรณีไปต่อไม่ได้แล้ว
            break;

        int vert = vertex.front();
        vertex.pop();
        if(non_team[vert] == 1) continue;
        //cout << vert << "\n";

        for(auto xx=adj[vert].begin();xx!=adj[vert].end();xx++){
            int next = *xx;
            if(non_team[next] == 1) continue;
            if(bipar[next] == 0) // bipar 0 = ไม่เคยไป push เข้าได้
                vertex.push(next);
            if(bipar[next] == 0) // ทำให้ค่า bipar ของตัวที่ไปได้เป็น ตรงข้ามของ parent
                bipar[next] = -1*bipar[vert];
            else if(bipar[vert] == bipar[next]){
                // กรณีไม่เป็น 0 = สามารถไปได้จาก node parent => ต้องเช็คเงื่อนไข
                check = 1; // เบรคออก กรณีไม่ตรงเงื่อนไข ใช้ check ในการเลือกคำตอบ
                break;
            }
        }
        if(check)
            break;
    }
    if(check == 1) // check เลือกคำตอบ
        cout << "no" << '\n';
    else cout << "yes" << '\n';


}