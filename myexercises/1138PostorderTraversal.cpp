#include <iostream>
#include <vector>
using namespace std;
const int maxn = 50010;
int n, pre[maxn], in[maxn];
vector<int> postorder;
void post(int root, int start, int end) {
  if (start > end) {
    return;
  }
  int i = start;
  while (i <= end && in[i] != pre[root]) {
    i++;
  }
  post(root + 1, start, i - 1);
  post(root + i - start + 1, i + 1, end);
  postorder.push_back(pre[root]);
  // std::cout << pre[root] << std::endl;
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pre[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }
  post(0, 0, n - 1);
  std::cout << postorder[0] << std::endl;
  fclose(stdin);
  return 0;
}