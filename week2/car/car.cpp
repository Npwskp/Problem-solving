#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int perform[n];
    for(int i=0;i<n;i++){
        int p,v;
        cin >> p >> v;
        perform[i] = v;
    }
    int min = perform[n-1] ,count = 0;
    for(int i=n-1;i>=0;i--){
        if(min <= perform[i]){
            min = perform[i];
        }
        else{
            count++;
        }
    }
    cout << count ;
}