#include <bits/stdc++.h>
using namespace std;

int n;
int weight[1005], val[1005], max_idx = -1, max_val = 0, connect[1005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        weight[i] = 1;
        val[i] = tmp;
    }

    for (int i = 0; i < n; i++)
    {
        int maxx = 0, idx = 0;
        for (int j = 0; j < i; j++)
        {
            if (weight[j] > maxx && val[j] < val[i])
            {
                idx = j;
                maxx = weight[j];
            }
        }
        weight[i] += maxx;
        if (weight[i] > max_val)
        {
            max_val = weight[i];
            max_idx = i;
        }
        connect[i] = idx;
        //cout << i << " " << idx << "\n";
    }

    cout << max_val << "\n";
    vector<int> ans;
    while (1)
    {
        if (max_val == 0)
            break;
        ans.push_back(val[max_idx]);
        //cout << max_idx << " " << connect[max_idx] << "\n";
        max_idx = connect[max_idx];
        max_val--;
    }

    for (int i = ans.size()-1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}