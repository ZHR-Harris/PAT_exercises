#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, m, k;
vector<int> adj[maxn];
bool vis[maxn] = {false};
void dfs(int root) {
  vis[root] = true;
  for (int i = 0; i < adj[root].size(); i++) {
    // std::cout << i << std::endl;
    // std::cout << adj[root].size() << std::endl;
    if (!vis[adj[root][i]]) {
      dfs(adj[root][i]);
    }
  }
  // for (auto lt = adj[root].begin(); lt != adj[root].end(); lt++) {
  //   // std::cout << *lt << std::endl;
  //   if (!vis[*lt]) {
  //     dfs(*lt);
  //   }
  // }
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < k; i++) {
    fill(vis, vis + maxn, false);
    int city, cnt = 0;
    cin >> city;
    vis[city] = true;

    for (int j = 1; j <= n; j++) {
      if (vis[j] == false) {
        dfs(j);
        cnt++;
      }
    }
    std::cout << cnt - 1 << std::endl;
  }
  fclose(stdin);
  return 0;
}