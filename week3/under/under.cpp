#include<iostream>
#include<vector>
using namespace std;

int main(){
    int l,n;
    cin >> l >> n;
    int arr[2*l+5],max = -99999;
    for(int i=0;i<2*l+5;i++){
        arr[i] = 0;
    }
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        for(int j=2*x+1;j<2*y;j++){
            arr[j] += 1;
            if(arr[j] > max)
                max = arr[j];
        }

    }
    cout << max;
}