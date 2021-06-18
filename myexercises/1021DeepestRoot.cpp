#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int maxn = 10010;
bool vis[maxn] = {false};
int n, cnt = 0, maxh = -1;
vector<int> v[maxn];
set<int> temp;
void bfs(int p) {
  queue<int> q;
  q.push(p);
  vis[p] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    vis[now] = true;
    for (int i = 0; i < v[now].size(); i++) {
      int a = v[now][i];
      if (!vis[a]) {
        q.push(a);
      }
    }
  }
}

void dfs(int p, int h) {
  vis[p] = true;
  if (h > maxh) {
    maxh = h;
    temp.clear();
    temp.insert(p);
  } else if (h == maxh) {
    temp.insert(p);
  }
  for (int i = 0; i < v[p].size(); i++) {
    if (!vis[v[p][i]]) {
      dfs(v[p][i], h + 1);
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      bfs(i);
      cnt++;
    }
  }
  if (cnt > 1) {
    printf("Error: %d components\n", cnt);
  } else {
    for (int i = 1; i <= n; i++) {
      fill(vis, vis + 10010, false);
      dfs(i, 0);
    }
    for (auto i = temp.begin(); i != temp.end(); i++) {
      std::cout << *i << std::endl;
    }
  }

  fclose(stdin);
  return 0;
}