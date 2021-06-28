#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 510, INF = 0x3fffffff;
struct node {
  int v, w;
  node(int v_, int w_) : v(v_), w(w_){};
};
vector<node> adj[maxn];
bool vis[maxn] = {false};
int d[maxn], teamNum[maxn], pathNum[maxn], rescueNum[maxn];
int n, m, c1, c2;

void dijkstra(int s) {
  d[s] = 0;
  pathNum[s] = 1;
  rescueNum[s] = teamNum[s];
  for (int i = 0; i < n; i++) {
    int u = -1, min = INF;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && d[j] < min) {
        u = j;
        min = d[j];
      }
    }
    if (u == -1) {
      return;
    }
    // std::cout << u << std::endl;
    vis[u] = true;
    for (int k = 0; k < adj[u].size(); k++) {
      int v = adj[u][k].v;
      int w = adj[u][k].w;
      if (!vis[v]) {
        if (d[u] + w < d[v]) {
          d[v] = d[u] + w;
          rescueNum[v] = rescueNum[u] + teamNum[v];
          pathNum[v] = pathNum[u];
          printf("%d %d\n", pathNum[v], pathNum[u]);
        } else if (d[u] + w == d[v]) {
          if (rescueNum[u] + teamNum[v] > rescueNum[v]) {
            rescueNum[v] = rescueNum[u] + teamNum[v];
          }
          pathNum[v] += pathNum[u];
          printf("%d %d\n", pathNum[v], pathNum[u]);
        }
      }
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n >> m >> c1 >> c2;
  for (int i = 0; i < n; i++) {
    cin >> teamNum[i];
  }
  fill(d, d + maxn, INF);
  // fill(pathNum, pathNum + maxn, 1);
  fill(rescueNum, rescueNum + maxn, 0);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(node(v, w));
    adj[v].push_back(node(u, w));
  }

  dijkstra(c1);
  std::cout << pathNum[c2] << " " << rescueNum[c2] << std::endl;
  // for (int i = 0; i < n; i++) {
  //   std::cout << pathNum[i] << std::endl;
  // }
  // std::cout << "  " << std::endl;
  // for (int i = 0; i < n; i++) {
  //   std::cout << rescueNum[i] << std::endl;
  // }
  fclose(stdin);
  return 0;
}