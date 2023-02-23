#include <bits/stdc++.h>
using namespace std;

int n,tmp,ans = 1;
pair<int,int> sch[100005];

bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        sch[i] = {x,y};
    }
    sort(sch,sch+n,myComparison);
    /*for (int i = 0; i < n; i++){
        cout << sch[i].first << ' ' << sch[i].second << '\n';
    }*/
    tmp = sch[0].second;
    for (int i = 0; i < n; i++)
    {
        if(sch[i].first >= tmp){
            ans++;
            tmp = sch[i].second;
        }
    }
    cout << ans;
}