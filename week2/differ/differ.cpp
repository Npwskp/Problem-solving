#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num[n];
    set<int> ans;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        num[i] = tmp;
    }
    for(int i=0;i<n;i++){
        int k = 0;
        for(int j=i;j<n;j++){
            k+=num[j];
            ans.insert(k);
        }
    }
    cout << ans.size() ;
}