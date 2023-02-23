#include <iostream>

int main(){
    int num[300];
    int n,max;
    max = 0;
    std::cin >> n;
    for(int i = 0; i < 300; i++){
        num[i] = 0;
    }
    for(int i = 0; i < n; i++){
        int tmp;
        std::cin >> tmp;
        num[tmp] += 1;
        if(num[tmp] > max)
            max = num[tmp];
    }
    if (max < 2)
      max = 2;
    std::cout << max;
}