#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans[n],count = 0;
  for(int i=0;i<n;i++){
    int tmp;
    cin >> tmp;
    ans[i] = tmp;
    for(int j=0;j<i;j++){
      if(ans[j]<tmp){
        count++;
      }
    }
  }
  cout << count;
}