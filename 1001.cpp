#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  int a, b, sum, len = 0, mul3 = 0;
  cin >> a >> b;
  sum = a + b;
  char num[20];
  if (sum == 0)
  {
    std::cout << '0' << std::endl;
    return 0;
  }

  if (sum < 0)
  {
    std::cout << "-";
  }
  // sum = abs(sum);
  sum = sum < 0 ? -sum : sum;
  while (sum != 0)
  {
    if (mul3 != 0 && mul3 % 3 == 0)
    {
      num[len++] = ',';
    }
    num[len++] = sum % 10 + '0'; // ！！注意，+'0'是为了通过阿斯卡码把数字变成字符
    sum /= 10;
    mul3++;
  }
  for (int i = len - 1; i >= 0; i--)
  {
    std::cout << num[i];
  }
  std::cout << "" << std::endl;

  /* your code */
  fclose(stdin);
  return 0;
}