#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 110;
struct node {
  int id, k, level;
  int childs[maxn];
  node() {
    k = 0;
  };
} nodes[maxn];
int level[maxn], max_level = -1;
int n, m;

void levelorder() {
  queue<node> q;
  q.push(nodes[1]);
  while (!q.empty()) {
    node now = q.front();
    for (int i = 0; i < now.k; i++) {
      node child = nodes[now.childs[i]];
      child.level = now.level + 1;
      if (child.k == 0) {
        level[child.level]++;
        // std::cout << child->level << std::endl;
      }
      // std::cout << level[child->level] << std::endl;
      if (child.level > max_level) {
        max_level = child.level;
      }
      q.push(child);
    }
    q.pop();
  }
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  fill(level, level + maxn, 0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int id, k;
    cin >> id >> k;
    nodes[id].k = k;
    for (int j = 0; j < k; j++) {
      cin >> nodes[id].childs[j];
    }
  }
  levelorder();
  std::cout << level[0];
  for (int i = 1; i <= max_level; i++) {
    std::cout << " " << level[i];
  }
  std::cout << "" << std::endl;
  fclose(stdin);
  return 0;
}