#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int visited[30][30],n,m;
char arr[30][30];
int level1=0,level2=0,check=0;
queue<vector<int>> q;
vector<vector<int>> start;

void findarea(){
    for(int i=0;i<start.size();i++){
        vector<int> st = start[i];
        int area = 0;
        if(visited[st[0]][st[1]] == 1)
            continue;
        q.push(st);
        char a_type = arr[st[0]][st[1]];
        if(a_type == '*' || a_type == '$')
            check = 1;
        while(!q.empty()){
            vector<int> a = q.front();
            q.pop();
            int x = a[0],y = a[1];
            if(x < 0 || x >= n || y < 0 || y>= m)
                continue;
            char tmp = arr[x][y];
            if(tmp == '#')
                continue;
            if(tmp != '#' && visited[x][y] == 0){
                area++;
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x,y-1});
                if(tmp == '*' && a_type == '$' && check <= 2)
                    check++;
                else if (tmp == '$' && a_type == '*' && check <= 2)
                    check++;
            }
            visited[x][y] = 1;
        }
        if(check == 1)
            level1 += area;
        else if(check == 2)
            level2 += area;
    }
    return ;
}

int main(){
    cin >> n >> m;
    //cout << n << m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp;
            visited[i][j] = 0;
            if(tmp == '*' || tmp == '$')
                start.push_back({i,j});
        }
    }
    findarea();
    cout << level2 << ' ' << level1 ;
}