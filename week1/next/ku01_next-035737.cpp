#include <iostream>
using namespace std;

int arrmain[100010];
int ans[100010];
int main(){
    int max = 0;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        arrmain[i+1] = tmp;
    }

    int idx;
    idx = 1;
    while(1){
        if (idx == n)
            break;
        if(arrmain[idx] == 0)
          idx++;
        else{
          int itmp = idx;
          int count = 0;
          while(1){
            int t;
            t = arrmain[itmp];
            arrmain[itmp] = 0;
            itmp = t;
            count ++;
            if(itmp == idx)
              break;
          }
          if (count>max)
            max = count;
        idx++;
        }
    }
    cout << max;
}