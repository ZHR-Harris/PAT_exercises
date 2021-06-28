#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1100, INF = 0x3fffffff;
int n, m, k, ds;
struct node {
  int v, w;
  node(int v_, int w_) : v(v_), w(w_){};
};
vector<node> adj[maxn];
int d[maxn];
float min_dis[maxn], average_dis[maxn];
bool vis[maxn] = {false}, solution[maxn] = {true};
void dijkstra(int s) {
  d[s] = 0;
  for (int i = 0; i < n + m; i++) {
    int u = -1, min = INF;
    for (int j = 1; j <= n + m; j++) {
      if (!vis[j] && d[j] < min) {
        u = j;
        min = d[j];
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
      }
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n >> m >> k >> ds;
  for (int i = 0; i < k; i++) {
    char a[3], b[3];
    int a_, b_, d;
    cin >> a >> b >> d;
    a_ = (a[0] == 'G') ? n + a[1] - '0' : a[0] - '0';
    b_ = (b[0] == 'G') ? n + b[1] - '0' : b[0] - '0';
    adj[a_].push_back(node(b_, d));
    adj[b_].push_back(node(a_, d));
  }
  for (int i = 1; i <= m; i++) { //循环m次，对每个候选点做dijkstra
    fill(d, d + maxn, INF);
    fill(vis, vis + maxn, false);
    dijkstra(i + n);
    int mind = INF;
    float sum = 0.0;
    bool flag = false;
    for (int j = 1; j <= n; j++) {
      if (d[j] > ds) {
        solution[i] = false;
        flag = true;
        break;
      }
      mind = min(mind, d[j]);
      sum += d[j];
    }
    if (flag) {
      min_dis[i] = -1;
      continue;
    }
    min_dis[i] = mind;
    average_dis[i] = sum / (float)n;
  }

  float maxn = -1, average;
  int index;
  bool hasSolution = false;
  for (int i = 1; i <= m; i++) {
    if (solution[i] == true) {
      hasSolution = true;
    }
    if (min_dis[i] > maxn) {
      maxn = min_dis[i];
      index = i;
    } else if (min_dis[i] == maxn) {
      if (average_dis[i] < average) {
        index = i;
        average = average_dis[i];
      }
    }
  }
  if (!hasSolution) {
    printf("G%d\n", index);
    printf("%.1f %.1f\n", min_dis[index],
           round(average_dis[index] * 10.0) / 10.0);

  } else {
    std::cout << "No solution" << std::endl;
  }

  fclose(stdin);
  return 0;
}