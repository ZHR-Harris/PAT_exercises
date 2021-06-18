#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 11000;
const int INF = 0x3fffffff;
int n, m, k, d;
struct edge {
  int v;
  int dis;
  edge(int v_, int dis_) : v(v_), dis(dis_){};
};
vector<edge> adj[maxn];
int dis[maxn][maxn]; //每个station到房屋的距离
bool vis[maxn] = {false};

void dijkstra(int s) {
  dis[s][s] = 0;
  fill(vis, vis + maxn, false);
  for (int i = 0; i < n + m; i++) {
    int u = -1, min = INF;
    for (int j = 1; j <= n + m; j++) {
      if (!vis[j] && dis[s][j] < min) {
        u = j;
        min = dis[s][j];
      }
    }
    if (u == -1) {
      return;
    }
    // std::cout << u << std::endl;
    vis[u] = true;
    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j].v;
      int d = adj[u][j].dis;
      // std::cout << v << " " << d << " " << dis[s][u] << " " << dis[s][v]
      // << std::endl;
      if (!vis[v] && dis[s][u] + d < dis[s][v]) {
        dis[s][v] = dis[s][u] + d;
      }
    }
  }
}

int convert(string str) {
  if (str[0] == 'G') {
    if (str.length() == 3) {
      return n + 10;
    } else if (str.length() == 2) {
      return n + str[1] - '0';
    }
  } else {
    int x = 0;
    for (int i = 0; i < str.length(); i++)
      x = x * 10 + str[i] - '0';
    return x;
  }
  return 0;
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n >> m >> k >> d;

  for (int i = 0; i < k; i++) {
    string p1, p2;
    int dis;
    cin >> p1 >> p2 >> dis;
    int a = convert(p1);
    int b = convert(p2);
    adj[a].push_back(edge(b, dis));
    adj[b].push_back(edge(a, dis));
  }
  for (int i = 0; i <= m + n + 1; i++) {
    fill(dis[i], dis[i] + m + n + 1, INF);
  }

  for (int i = n + 1; i <= n + m; i++) {
    dijkstra(i);
  }

  for (int i = n + 1; i <= n + m; i++) {
    sort(dis[i] + 1, dis[i] + n);
  }
  int index = -1, max_min_dis = -1;
  for (int i = n + 1; i <= n + m; i++) {
    for (int j = 1; j <= n; j++) {
      if (dis[i][j] > d) {
        fill(dis[i] + 1, dis[i] + m + n + 1, -2);
      }
    }
    if (dis[i][1] > max_min_dis) {
      index = i;
      max_min_dis = dis[i][1];
    }
  }

  if (index == -1) {
    std::cout << "No solution" << std::endl;
  } else {
    double total_dis = 0;
    for (int i = 1; i <= n; i++) {
      total_dis += dis[index][i];
    }
    std::cout << "G" << index - n << std::endl;
    printf("%.1f %.1f\n", max_min_dis * 1.0, total_dis * 1.0 / n);
  }

  fclose(stdin);
  return 0;
}