#include <bits/stdc++.h>
#define int long long
using namespace std;
 main()
{
    vector<int> vec, vecplus, vecminus;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        vec.push_back(x);
        vecplus.push_back(x);
        vecminus.push_back(-x);
    }
    sort(vecplus.begin(), vecplus.end());
    sort(vecminus.begin(), vecminus.end());
    int maxDiff = 0;
    for (int i = 1; i < vec.size() - 1; i++)
    {
        if (vec[i] > vec[i - 1] && vec[i] > vec[i + 1])
        {
        }
        else if (vec[i] < vec[i - 1] && vec[i] < vec[i + 1])
        {
        }
        else
        {
            continue;
        }
        int oldval = abs(vec[i] - vec[i - 1]) + abs(vec[i] - vec[i + 1]);
        int newval = oldval;
        int valmin = min(vec[i + 1], vec[i - 1]);
        int valmax = max(vec[i + 1], vec[i - 1]);
        int upperMinIdx = lower_bound(vecplus.begin(), vecplus.end(), valmin + 1) - vecplus.begin();    // val > 12 <15
        int lowerMaxIdx = lower_bound(vecminus.begin(), vecminus.end(), -valmax + 1) - vecminus.begin(); // val > -15 <-12
        if (upperMinIdx != vec.size())
        {
            int changeVal = vecplus[upperMinIdx];
            if (changeVal != valmax)
            {
                newval = abs(changeVal - vec[i - 1]) + abs(changeVal - vec[i + 1]);
                maxDiff = max(maxDiff, oldval - newval);
            }
        }
        if (lowerMaxIdx != vec.size())
        {
            int changeVal = -vecminus[lowerMaxIdx];
            if (changeVal != valmin)
            {
                newval = abs(changeVal - vec[i - 1]) + abs(changeVal - vec[i + 1]);
                maxDiff = max(maxDiff, oldval - newval);
            }
        }
        int upperMaxIdx = lower_bound(vecplus.begin(), vecplus.end(), valmax + 1) - vecplus.begin();    // val > 15
        int lowerMinIdx = lower_bound(vecminus.begin(), vecminus.end(), -valmin + 1) - vecminus.begin(); // val <-12
        if (upperMaxIdx != vec.size())
        {
            int changeVal = vecplus[upperMaxIdx];
            newval = abs(changeVal - vec[i - 1]) + abs(changeVal - vec[i + 1]);
            maxDiff = max(maxDiff, oldval - newval);
        }
        if (lowerMinIdx != vec.size())
        {
            int changeVal = -vecminus[lowerMinIdx];
            newval = abs(changeVal - vec[i - 1]) + abs(changeVal - vec[i + 1]);
            maxDiff = max(maxDiff, oldval - newval);
        }
    }
    int val=0;
    for(int i=1;i<vec.size();i++){
        val += abs(vec[i-1]-vec[i]);
    }
    cout << val-maxDiff;
}
