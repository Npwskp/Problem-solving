#include <iostream>
#include <cmath>

int main(){
  int n,x,y,i,sum;
  sum = 0;
  float radius;
  std::cin >> n;
  for (int i = 0; i < n; i++){
    std::cin >> x >> y;
    radius =  sqrt(x*x + y*y);
    if (radius <= 2)
      sum += 5;
    else if (radius <= 4)
      sum += 4;
    else if (radius <= 6)
      sum += 3;
    else if (radius <= 8)
      sum += 2;
    else if (radius <= 10)
      sum += 1;
  }
  std::cout << sum << std::endl;
}