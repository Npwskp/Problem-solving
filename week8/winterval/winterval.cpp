#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int, int>> arr;
int weight[1005],connect[1005],max_idx,max_w;
vector<int> ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({a, b});
        weight[i] = c;
    }
    for (int i = 0; i < n; i++)
    {
        int x,y,maxx = 0,idx = 0;
        tie(x,y) = arr[i];
        //cout << "Round : " << i << " : " ;
        for (int j = 0; j < i; j++)
        {
            //cout << "{ " << j << " " << weight[j] << " } ";
            int xj,yj;
            tie(xj,yj) = arr[j];
            if(yj <= x && weight[j] > maxx){
                idx = j;
                maxx = weight[j];
                //cout << maxx << " ";
            }
        }
        //cout << "\n";
        weight[i] += maxx;
        if(weight[i] > max_w){
            max_w = weight[i];
            max_idx = i;
        }
        //cout << "Max : "<< max_w << " " << weight[i] << " " << max_idx << "\n";
        connect[i] = maxx==0?i:idx;
    }
    cout << weight[max_idx] << "\n";

    while (1)
    {
        ans.push_back(max_idx+1);
        if (max_idx == connect[max_idx])
            break;
        //cout << max_idx << " ";
        max_idx = connect[max_idx];
        
    }
    cout << ans.size() << "\n";
    for (int i = ans.size()-1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}