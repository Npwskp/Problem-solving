#include <bits/stdc++.h>
using namespace std;

int n;
int m, k;
int arr[100005][2];
map<int, int> ch[100005];

int minn(int a, int b)
{
    return a < b ? a : b;
}

int hp_cal(int i, int diff)
{
    if (i >= m)
    {
        if (diff >= -k && diff <= k)
            return 0;
        else
            return 1e9;
    }
    if (ch[i][diff] != -1)
        return ch[i][diff];

    int hp1 = arr[i][0];
    int hp2 = arr[i][1];
    if (diff >= -k && diff <= k)
    {
        int aa = hp_cal(i + 1, diff - 1);
        aa += hp1;
        int bb = hp_cal(i + 1, diff + 1);
        bb += hp2;
        return ch[i][diff] = min(aa, bb);
    }
    else
    {
        return ch[i][diff] = 1e9;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> k;
        for (int j = 0; j < m; j++)
        {
            int a, b;
            cin >> a >> b;
            arr[j][0] = a;
            arr[j][1] = b;
            for (int xx = -210; xx <= 210; xx++)
            {
                ch[j][xx] = -1;
            }
        }
        cout << hp_cal(0, 0) << "\n";
    }
}