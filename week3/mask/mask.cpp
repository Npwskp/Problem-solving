#include<iostream>
#include<map>
using namespace std;

int checkwin(int x,int y){
    if(x>y) return x;
    else return y;
}

int checklose(int x,int y){
    if(x>y) return y;
    else return x;
}

int main(){
    int n,max = -9999,i=0,max_idx = 0;
    cin >> n;
    int arr[4];
    map<int,int> num;
    for(i=0;i<4*n;i++){
        int tmp;
        cin >> tmp;
        if(tmp > max){
            max = tmp;
            max_idx = i;
        }
        if(i%n == n-1){
            arr[i/n] = max;
            num[max]=max_idx+1;
            max = -9999;
        }
    }
    int winA = checkwin(arr[0],arr[1]),winB = checkwin(arr[2],arr[3]);
    int loseA = checklose(arr[0],arr[1]),loseB = checklose(arr[2],arr[3]);
    if(winA > winB) cout << num[winA] << ' ' << num[winB] << ' ';
    else cout << num[winB] << ' ' << num[winA ]<< ' ';
    cout << num[loseA] << ' ' << num[loseB];
}
