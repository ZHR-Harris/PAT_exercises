#include <iostream>
using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  int A[7] = {1, 2, 3, -1, -2, 7, 9};
  int dp[7] = {1};
  int maxn = -1;
  for (int i = 1; i < 7; i++) {
    for (int j = 0; j < i; j++) {
      if (A[j] < A[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        maxn = max(maxn, dp[i]);
      }
    }
  }
  std::cout << maxn << std::endl;
  fclose(stdin);
  return 0;
}