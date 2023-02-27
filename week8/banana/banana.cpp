#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005], weight[100005];

int banana(int xx)
{
    if (xx + 3 > n || xx + 1 > n)
        return 0;
    if (weight[xx] != -1)
    {
        return weight[xx];
    }
    else
    {
        int check = max(banana(xx + 1), banana(xx + 3) + arr[xx + 2]);
        weight[xx] = check;
        return check;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        weight[i] = -1;
    }
    cout << banana(0);
}