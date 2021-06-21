#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10010;
int n, num[maxn], dp[maxn], maxsum = -1;
vector<int> v[maxn];
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  dp[0] = num[0];
  for (int i = 1; i < n; i++) {
    dp[i] = max(num[i], num[i] + dp[i - 1]);
    if (dp[i - 1] > 0) {
      v[i] = v[i - 1];
    }
    v[i].push_back(num[i]);
    maxsum = max(dp[i], maxsum);
  }
  if (maxsum < 0) {
    printf("%d %d %d\n", 0, num[0], num[n - 1]);
  } else {
    for (int i = 0; i < n; i++) {
      if (dp[i] == maxsum) {
        printf("%d %d %d\n", maxsum, v[i].front(),
               *(v[i].begin() + v[i].size() - 1));
        break;
      }
    }
  }

  fclose(stdin);
  return 0;
}