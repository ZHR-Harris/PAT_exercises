#include <iostream>
#include <string>
using namespace std;
const int maxn = 2000;
int dp[maxn][maxn], ans = 1; // 注意ans要初始化为1
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  string s;
  getline(cin, s);
  for (int i = 0; i < s.length(); i++) {
    dp[i][i] = 1;
    if (i < s.length() - 1 && s[i] == s[i + 1]) {
      dp[i][i + 1] = 1;
      ans = 2;
    }
  }
  for (int len = 3; len <= s.length(); len++) { // 注意len可以等于s.length()
    for (int i = 0; i + len - 1 < s.length(); i++) {
      int j = i + len - 1;
      if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
        dp[i][j] = 1;
        ans = len;
      }
    }
  }
  std::cout << ans << std::endl;

  fclose(stdin);
  return 0;
}