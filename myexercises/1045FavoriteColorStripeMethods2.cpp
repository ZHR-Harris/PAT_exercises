#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10010;
int n, m, num, love[210], l, A[maxn], dp[maxn], res = -1;

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  fill(dp, dp + maxn, 1);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a;
    cin >> a;
    love[a] = i;
  }
  cin >> l;
  for (int i = 0; i < l; i++) {
    int a;
    cin >> a;
    if (love[a] >= 1) {
      A[num++] = love[a];
    }
  }
  // std::cout << num << std::endl;
  for (int i = 0; i < num; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (A[j] <= A[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  std::cout << res << std::endl;
  fclose(stdin);
  return 0;
}