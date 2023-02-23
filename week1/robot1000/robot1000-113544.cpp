#include <iostream>
#include <string>
using namespace std;

int main(){
  string str;
  int corx = 0,cory = 0;
  cin >> str;
  int len = str.length();
  for(int i=0;i<len;i++){
    int x = str[i];
    if(x == 'N'){
      cory += 1;
    }
    if(x == 'E'){
      corx += 1;
    }
    if(x == 'W'){
      corx -= 1;
    }
    if(x == 'S'){
      cory -= 1;
    }
    if(x == 'Z'){
      corx = 0;
      cory = 0;
    }
  }
  cout << corx << ' ' << cory;
}