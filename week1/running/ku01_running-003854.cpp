#include <iostream>
#define int long long
using namespace std;

main() {
  int n,k,min;
  min = 999999999;
  cin >> n >> k;
  int time[n];
  for(int i=0;i<n;i++){
    int tmp;
    cin >> tmp;
    time[i] = tmp;
    if(min>tmp)
      min = tmp;
  }
  int check = min*(k);
  int count = 0;
  for(int i=0;i<n;i++){
    if(time[i]*(k-1) < check)
      count += 1;
  }
  cout << count;
}