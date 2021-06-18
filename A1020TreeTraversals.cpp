/*
已知后序与中序输出前序（先序）
*/
/*
#include <cstdio>
using namespace std;
int post[] = {3, 4, 2, 6, 5, 1};
int in[] = {3, 2, 4, 1, 6, 5};
void pre(int root, int start, int end) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    printf("%d ", post[root]);
    pre(root - 1 - end + i, start, i - 1);
root指post中，start end是inorder数组中的
    pre(root - 1, i + 1, end);
}

int main() {
    pre(5, 0, 5);
    return 0;
}

*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int maxn = 40;
int n, post[maxn], in[maxn];
map<int, int> mp;
void dfs(int root, int start, int end, int index) {
  if (start > end) {
    return;
  }
  int i = start;
  mp[index] = post[root];
  while (post[root] != in[i]) {
    i++;
  }
  dfs(root - (end - i + 1), start, i - 1, index * 2 + 1);
  dfs(root - 1, i + 1, end, index * 2 + 2);
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> post[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }
  dfs(n - 1, 0, n - 1, 0);
  auto it = mp.begin();
  std::cout << it->second;
  while (++it != mp.end()) {
    printf(" %d", it->second);
  }

  fclose(stdin);
  return 0;
}
