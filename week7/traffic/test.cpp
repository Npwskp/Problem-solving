#include "traffic.h"
#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

int n, k, ans = 0;

void checkTraf(int st, int ed, int i, int cor)
{
  int cc;
  if (cor == 0)
    cc = traffic_query(i, st, i, ed);
  else
    cc = traffic_query(st, i, ed, i);
  ans++;

  if (cc != ed - st && cc == 2)
  {
    if (cor == 0)
      traffic_report(i, st, i, st+1, 0, 0, 0, 0);
    else
      traffic_report(st, i, st+1, i, 0, 0, 0, 0);
    return;
  }

  int mid = (st + ed) / 2, cc2;
  if (cor == 0)
    cc2 = traffic_query(i, st, i, mid);
  else
    cc2 = traffic_query(st, i, mid, i);
  ans++;

  if (cc2 != mid - st)
  {
    checkTraf(st, mid, i, cor);
  }

  else
  {
    checkTraf(mid, ed, i, cor);
  }
}

int main()
{
  traffic_init(&n, &k);
  // traffic_report(1,1,2,1, 0,0,0,0);
  for (int i = 1; i <= n; i++)
  {
    if (traffic_query(i, 1, i, n) != n - 1)
    {
      checkTraf(1, n, i, 0);
      ans++;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (traffic_query(1, i, n, i) != n - 1)
    {
      checkTraf(1, n, i, 1);
      ans++;
    }
  }
  
}
