#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005][2];
int cost[100005][5];

int cost_cal(int i, int type)
{
    if (i >= n)
    {
        return 0;
    }
    int left_shift1, right_shift1;
    int both_shift2, left_shift2, right_shift2;
    // p[i] = min(A + p(i+1,1) -> B + p(i+1,0) , A+B + p(i+2,2))
    int A = arr[i][0];
    int B = arr[i][1];
    //cout << A << " " << B << "\n";
    if (type == 2)
    {
        // เลือกได้ 3 แบบเลย
        if (cost[i][0] == -1)
        {
            left_shift1 = cost_cal(i + 1, 1);
            cost[i][0] = left_shift1;
        }
        else
        {
            left_shift1 = cost[i][0];
        }
        if (cost[i][1] == -1)
        {
            right_shift1 = cost_cal(i + 1, 0);
            cost[i][1] = right_shift1;
        }
        else
        {
            right_shift1 = cost[i][1];
        }
        if (cost[i][2] == -1)
        {
            both_shift2 = cost_cal(i + 2, 2);
            cost[i][2] = both_shift2;
        }
        else
        {
            both_shift2 = cost[i][2];
        }
        return max({A + left_shift1, B + right_shift1, both_shift2});
    }
    else if(type == 0){
        if (cost[i][0] == -1)
        {
            left_shift1 = cost_cal(i + 1, 1);
            cost[i][0] = left_shift1;
        }
        else
        {
            left_shift1 = cost[i][0];
        }
        return max({A + left_shift1,cost_cal(i+1,2)});
    }
    else if(type == 1){
        if (cost[i][1] == -1)
        {
            right_shift1 = cost_cal(i + 1, 0);
            cost[i][1] = right_shift1;
        }
        else
        {
            right_shift1 = cost[i][1];
        }
        return max({B + right_shift1,cost_cal(i+1,2)});
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if(x < 0) x = 0;
        if(y < 0) y = 0;
        arr[i][0] = x;
        arr[i][1] = y;
        for (int j = 0; j < 5; j++)
        {
            cost[i][j] = -1;
        }
    }
    cout << cost_cal(0, 2);
}