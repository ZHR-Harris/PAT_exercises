#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 510;
const int INF = 0x3fffffff;
int cmax, n, spr, m;
int c[maxn], d[maxn]; //定义每个车站的车辆数，到起始点的距离；
bool vis[maxn] = {false};
vector<int> pre[maxn];

struct node
{
  int v, w;
  node(int a, int b) : v(a), w(b){};
};
vector<node> adj[maxn];

void dijkstra(int s)
{
  fill(d, d + maxn, INF);
  d[s] = 0;
  for (int i = 0; i < n; i++) // i <=n ???
  {
    int min = INF, u = -1;
    for (int j = 0; j < n; j++)
    {
      if (vis[j] == false && d[j] < min)
      {
        min = d[j];
        u = j;
      }
    }
    if (u == -1)
    {
      return;
    }
    vis[u] = true;
    for (int j = 0; j < adj[u].size(); j++) //内循环里不能用外循环相同的字母表示循环
    {
      int v = adj[u][j].v;
      int w = adj[u][j].w;
      if (vis[j] == false)
      {
        if (d[u] + w < d[v])
        {
          d[v] = d[u] + w;
          pre[v].clear();
          pre[v].push_back(u);
        }
        else if (d[u] + w == d[v])
        {
          pre[v].push_back(u);
        }
      }
    }
  }
}

int main()
{
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  int s1, s2, t;
  cin >> cmax >> n >> spr >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> s1 >> s2 >> t;
    adj[s1].push_back(node(s2, t));
    adj[s2].push_back(node(s1, t));
  }

  /* your code */
  fclose(stdin);
  return 0;
}