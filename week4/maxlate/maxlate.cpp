#include <bits/stdc++.h>
using namespace std;

int n,timed = 0,late = 0;
pair<int,int> sch[100005];

int main(){
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        sch[i] = {x,y};
    }
    sort(sch,sch+n);
    /*for (int i = 0; i < n; i++)
        cout << sch[i].first << ' ' << sch[i].second << '\n';*/
    for (int i = 0; i < n; i++)
    {   
        timed += sch[i].second;
        if(timed-sch[i].first-10 > late)
            late = timed-sch[i].first-10;
    }
    cout << (late)*1000;
}