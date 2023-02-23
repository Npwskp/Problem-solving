#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k; //มีจำนวน k graph ให้เช็ค
    vector<string> ans;
    for(int i=0;i<k;i++){
        int m,n;
        cin >> n >> m; //รับ node ,edge

        vector<int> adj[100005]; //ตั้งค่าใน loop เพราะจะได้รีใหม่ทุกครั้งของกราฟใหม่
        int bipar[100005]; // สำหรับการแบ่งเป็น 2 กลุ่ม มี 1 กับ -1
                           // ใช้เป็น check visit ด้วย
        for(int j=0;j<m;j++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            bipar[j] = 0; //ตั้ง bipar เป็น 0 ทุกตัวก่อน
        }
        
        queue<int> vertex;
        vertex.push(1); //  เริ่มที่ node 1 ใส่ค่า bipar
        bipar[1] = 1;
        int check = 0;
        while(!vertex.empty()){ //ทำ bfs
            int vert = vertex.front();
            vertex.pop();
            for(auto xx=adj[vert].begin();xx!=adj[vert].end();xx++){
                int next = *xx;
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
}