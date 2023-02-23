#include <iostream>

int main(){
  int n,sum;
  std::cin >> n;
  sum = 0;
  for( int i = 0; i < n ; i++){
    int tmp;
    std::cin >> tmp;
    if(tmp > 0)
      sum += tmp;
  }
  std::cout << sum;
}