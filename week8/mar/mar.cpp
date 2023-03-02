#include <bits/stdc++.h>
using namespace std;

int n;
int cc[1005][30][30];

int normalize(int xx, int wh)
{
    // turn right
    int tr = abs(wh - xx);
    // turn left
    int tl = 26 - tr;
    return min(tr, tl);
}

int calculate(string str, int i, int wh1, int wh2)
{
    int xx = (int)str[i] - 65;
    if (i >= str.length())
    {
        return 0;
    }
    int tw1 = normalize(xx, wh1);
    int tw2 = normalize(xx, wh2);
    if (cc[i][wh1][wh2] == -1)
    {
        int ans = min(normalize(xx, wh1) + calculate(str, i + 1, xx, wh2), normalize(xx, wh2) + calculate(str, i + 1, wh1, xx));
        cc[i][wh1][wh2] = ans;
        return ans;
    }
    else
    {
        return cc[i][wh1][wh2];
    }
}

int main()
{
    cin >> n;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < tmp.length(); j++)
        {
            for (int k = 0; k < 30; k++)
            {
                for (int w = 0; w < 30; w++)
                {
                    cc[j][k][w] = -1;
                }
            }
        }
        cout << calculate(tmp, 0, 0, 0) << "\n";
    }
}