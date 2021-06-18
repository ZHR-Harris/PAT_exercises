// #include <cstdin>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn = 100000;
int n, m, k, p;
vector<int> graph[maxn];

int main() {
// #ifdef Onlinejudge
// #else
//   freopen("1.txt", "r", stdin);
// #endif //
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  // for (int i = 0; i < n; i++) {
  //   std::cout << "vertex " << i << " ";
  //   for (int j = 0; j < graph[i].size(); j++) {
  //     printf("%d ", graph[i][j]);
  //     /* code */
  //   }
  //   std::cout << "" << std::endl;
  //   /* code */
  // }
  cin >> p;
  for (int i = 0; i < p; i++) {
    int colors[maxn];
    set<int> a;
    bool flag = false;
    for (int j = 0; j < n; j++) {
      cin >> colors[j];
      a.insert(colors[j]);
      /* code */
    }

    for (int k = 0; k < n; k++) {
      for (int l = 0; l < graph[k].size(); l++) {
        if (colors[k] == colors[graph[k][l]]) {
          flag = true;
          break;
        }
      }
      if (flag)
        break;
      /* code */
    }
    if (flag) {
      std::cout << "No" << std::endl;
    } else {
      std::cout << a.size() << "-coloring" << std::endl;
    }
  }

  // fclose(stdin);
  return 0;
}
