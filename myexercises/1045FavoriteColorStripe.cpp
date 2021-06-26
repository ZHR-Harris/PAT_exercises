#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10010;
int n, love[maxn], l, A[maxn], dp[maxn] = {1}, maxnum = -1;
vector<int> v[maxn];
int index(int num) {
  for (int i = 0; i < n; i++) {
    if (A[i] == num) {
      return i;
    }
  }
  return -1;
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> love[i];
    v[i].push_back(love[i]);
  }
  cin >> l;
  for (int i = 0; i < l; i++) {
    cin >> A[i];
  }
  for (int i = 1; i < l; i++) {
    for (int j = 0; j < i; j++) {
      if (dp[i] < dp[j] + 1 && love[index(A[j]) + 1] == A[i] || A[i] == A[j]) {
        dp[i] = dp[j] + 1;
        v[i] = v[j];
        v[i].push_back(A[j]);
      }
    }
    maxnum = max(maxnum, dp[i]);
  }
  for (int i = 0; i < n; i++) {
    std::cout << v[i].size() << std::endl;
  }
  // for (int i = 0; i < v[n - 1].size(); i++) {
  //   std::cout << v[n - 1][i] << std::endl;
  // }

  // std::cout << maxnum << std::endl;
  fclose(stdin);
  return 0;
}