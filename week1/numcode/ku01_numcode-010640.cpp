#include <iostream>
using namespace std;

int check(int tmp ,int inpt){
  if(inpt == tmp+(tmp-1))
    return tmp-1;
  else if(inpt == tmp*2+(tmp+1))
    return tmp+1;
}

int main() {
  int n,t;
  cin >> n >> t;
  int tmp = n;
  int ans[n];
  if(t == 1){
    for(int i=0;i<n;i++){
      int inpt;
      cin >> inpt;
      if(inpt < tmp)
        ans[i] = 0;
      else if(inpt > tmp)
        ans[i] = 1;
      tmp = inpt;
    }
  }
  if(t == 2){
    for(int i=0;i<n;i++){
      int inpt;
      cin >> inpt;
      if(i==0){
        if(inpt < tmp)
            ans[i] = 0;
        else if(inpt > tmp)
            ans[i] = 1;
        tmp = inpt;
      }
      else{
        int xx = check(tmp,inpt);
        if(xx < tmp)
            ans[i] = 0;
        else if(xx > tmp)
            ans[i] = 1;
        tmp = check(tmp,inpt);
      }
    }
  }
  for(int i=0;i<n;i++){
    cout << ans[i] << '\n';
  }
}