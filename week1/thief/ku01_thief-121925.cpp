#include <iostream>
using namespace std;

int main() {
  int n,k,t;
  cin >> n >> k >> t;
  int idx = 1,count = 0;
  int arr[n+1];
  while(1){
    if(idx == 1 && count != 0)
      break;
    if(idx == t){
      count++;
      break;
    }
    count++;
    idx += k;
    if(idx > n)
      idx = idx-n;
  }
  cout << count;
}