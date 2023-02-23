#include<bits/stdc++.h>
using namespace std;

int n;
int arr[200005];
int maxx = 0;


int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        if(tmp-i < 0){
            tmp = n+tmp;
        }
        int xx = abs(tmp-i);
        arr[xx] += 1;
        if(arr[xx]>maxx)
            maxx = arr[xx];
    }
    cout << maxx;
}