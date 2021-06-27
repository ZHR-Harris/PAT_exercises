#include <iostream>
using namespace std;
const int maxn = 100;
int dp[maxn][maxn], res;
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  string s = "PATZJUJZTACCBCC";
  // fill(dp[0], dp[0] + maxn * maxn, 1);
  for (int i = 0; i < s.length(); i++) {
    dp[i][i] = 1;
    if (i < s.length() - 1) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = 1;
        res = 2;
      }
    }
  } // boundary
  for (int len = 3; len <= s.length(); len++) {
    for (int i = 0; i + len - 1 < s.length(); i++) {
      int j = i + len - 1;
      if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
        dp[i][j] = 1;
        res = len;
      }
    }
  }
  std::cout << res << std::endl;
  fclose(stdin);
  return 0;
}