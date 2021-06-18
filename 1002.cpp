#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  int num, exp;
  double coeff;
  map<int, double> mp;
  cin >> num;
  while (num--)
  {
    cin >> exp >> coeff;
    mp[exp] = coeff;
  }
  cin >> num;
  while (num--)
  {
    cin >> exp >> coeff;
    if (mp.count(exp) == 0)
    {
      mp[exp] = coeff;
    }
    else
    {
      mp[exp] += coeff;
      if (mp[exp] == 0)
      {
        mp.erase(exp); // 如果系数为0，要删除
      }
    }
  }
  std::cout << mp.size();
  for (map<int, double>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++) //反向迭代器，倒着输出map
  {
    std::cout << " " << setiosflags(ios::fixed) << setprecision(1) << it->first << " " << it->second;
  }
  std::cout << "" << std::endl;

  /* your code */
  fclose(stdin);
  return 0;
}