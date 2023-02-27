#include "probelib.h"
#include <iostream>
#include <cstdio>

int n;

bool probcheck(int st,int xx){
  if(st == xx) {
    probe_answer(xx);
    return true;
  }
  std::cout << st << " " << xx << "\n";
  int tmp = (xx+st)/2;
  if(probe_check(st,tmp)){
    return probcheck(st,tmp);
  }
  else{
    return probcheck((tmp+1),xx);
  }
}

main()
{
  int n = probe_init();

  probcheck(0,n-1);
}
