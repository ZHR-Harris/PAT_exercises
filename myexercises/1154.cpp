#include <iostream>
#include <set>
using namespace std;
const int maxn = 10010;
int edges[maxn][2];
int n, m, k;
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> edges[i][0] >> edges[i][1];
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int colors[maxn];
    set<int> s;
    bool flag = true;
    for (int j = 0; j < n; j++) {
      cin >> colors[j];
      s.insert(colors[j]);
    }
    for (int p = 0; p < m; p++) {
      int a = edges[p][0], b = edges[p][1];
      if (colors[a] == colors[b]) {
        std::cout << "No" << std::endl;
        flag = false;
        break;
      }
    }
    if (flag) {
      printf("%d-coloring\n", s.size());
    }
  }

  fclose(stdin);
  return 0;
}