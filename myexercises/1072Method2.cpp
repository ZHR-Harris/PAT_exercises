#include <algorithm>
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
bool vis[maxn] = {false};
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
  float ansmaxmin, ansaver = INF;
  int ansindex = -1;
  for (int index = 1; index <= m; index++) { //循环m次，对每个候选点做dijkstra
    fill(d, d + maxn, INF);
    fill(vis, vis + maxn, false);
    dijkstra(index + n);
    float nowmin = INF, sum = 0.0;
    for (int i = 1; i <= n; i++) { // 对于该候选点，每一点的距离
      // std::cout << d[i] << " " << ds << std::endl;
      if (d[i] > ds) {
        nowmin = -1;
        break;
      } else {
        if (d[i] < nowmin) {
          nowmin = d[i];
        }
        sum += d[i];
      }
    }
    if (nowmin == INF) {
      continue;
    } else {
      if (ansmaxmin < nowmin) {
        ansmaxmin = nowmin;
        ansindex = index;
        ansaver = sum / n;
      } else if (ansmaxmin == nowmin) {
        // std::cout << sum << std::endl;
        float aver = sum / n;
        if (aver < ansaver) {
          ansaver = aver;
          ansindex = index;
        }
      }
    }
  }
  if (ansindex == -1) {
    std::cout << "No solution" << std::endl;
  } else {
    printf("G%d\n%.1f %.1f\n", ansindex, ansmaxmin,
           round(ansaver * 10.0) / 10.0);
  }

  fclose(stdin);
  return 0;
}