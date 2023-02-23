#include <bits/stdc++.h>
using namespace std;

int checkvisit(int visited[100005],int n){
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            return i;
        }
    }
    return 0;
}

int main(){
    while(1){
        int n,m;
        vector<int> adj[100005];
        int degree[100005];
        int visited[100005];
        vector<int> ans;

        cin >> n >> m;

        if(n==0 && m==0) break;

        for(int i=1;i<=n;i++){
            degree[i] = 0;
            visited[i] = 0;
        }

        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            degree[v]++;
        }

        queue<int> q;
        for(int i=1;i<=n;i++){
            if(degree[i] == 0){
                q.push(i);
                //cout << i << '\n';
            }
        }
        if(q.empty())
            q.push(1);
        int check = 0;

        while(1){
            int cc = checkvisit(visited,n);
            if(q.empty() && cc != 0)
                q.push(cc);
            else if(q.empty() && cc == 0)
                break;

            int vert = q.front();
            q.pop();
            visited[vert] = 1;
            ans.push_back(vert);
            for(auto xx=adj[vert].begin();xx!=adj[vert].end();xx++){
                int next = *xx;
                if(visited[next] == 1){
                    check = 1;
                    break;
                }
                degree[next]--;
                if(degree[next] == 0)
                    q.push(next);
            }
            if(check == 1)
                break;
        }

        //cout << check << '\n';
        for(int i=0;i<ans.size();i++){
            if(i == ans.size()-1)
                cout << ans[i];
            else
                cout << ans[i] << ' ' ;
        }
        cout << endl;
    }
}