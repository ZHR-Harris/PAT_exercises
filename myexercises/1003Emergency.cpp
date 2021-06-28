#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000, INF = 0x3fffffff;
struct node {
  int v, w;
  node(int v_, int w_) : v(v_), w(w_){};
};
int n, m, c1, c2, d[maxn], hands[maxn], pathnum[maxn], handsnum[maxn];
bool vis[maxn] = {false};
vector<node> adj[maxn];
vector<int> pre[maxn];
void dijkstra() {
  for (int i = 0; i < n; i++) {
    int min = INF, u = -1;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && d[j] < min) {
        min = d[j];
        u = j;
      }
    }
    if (u == -1) {
      return;
    }
    vis[u] = true;
    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j].v, w = adj[u][j].w;
      if (!vis[v] && d[u] + w < d[v]) {
        d[v] = d[u] + w;
        pathnum[v] = pathnum[u];
        // pre[v].clear();
        // pre[v].push_back(u);
        handsnum[v] = hands[v] + handsnum[u];
      } else if (!vis[v] && d[u] + w == d[v]) {
        // pre[v].push_back(u);
        pathnum[v] += pathnum[u];
        if (hands[v] + handsnum[u] > handsnum[v]) {
          handsnum[v] = hands[v] + handsnum[u];
        }
      }
    }
  }
}

int hand(int d) {
  if (pre[d].size() == 1 && pre[d][0] == -1) {
    return hands[d];
  }
  int maxhands = 0;
  for (int i = 0; i < pre[d].size(); i++) {
    maxhands = max(maxhands, hand(pre[d][i]));
  }
  return maxhands + hands[d];
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  fill(d, d + maxn, INF);
  fill(pathnum, pathnum + maxn, 1);
  cin >> n >> m >> c1 >> c2;
  for (int i = 0; i < n; i++) {
    cin >> hands[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back(node(b, w));
    adj[b].push_back(node(a, w));
  }
  d[c1] = 0;
  handsnum[c1] = hands[c1];
  pre[c1].push_back(-1);
  dijkstra();
  printf("%d %d\n", pathnum[c2], handsnum[c2]);
  fclose(stdin);
  return 0;
}