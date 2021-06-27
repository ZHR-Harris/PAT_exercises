#include <iostream>
#include <string>
using namespace std;
const int maxn = 100;
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  int dp[maxn][maxn];

  string s1 = " sadstory", s2 = " adminsorry";  //注意下标从1开始
  int n = s1.length() - 1, m = s2.length() - 1; //长度要-1，第一位为空
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i] == s2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  std::cout << dp[n][m] << std::endl;
  fclose(stdin);
  return 0;
}