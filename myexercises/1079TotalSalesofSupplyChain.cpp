#include <iostream>
#include <vector>
using namespace std;
struct retailer {
  int index, amount;
  retailer(int i, int a) {
    index = i;
    amount = a;
  };
};
const int maxn = 100010;
int n, retailers[maxn];
double p, r, sum = 0;
vector<int> v[maxn];
bool vis[maxn] = {false};
// vector<retailer> retailers;
void dfs(int s, double rating) {
  vis[s] = true;
  if (v[s].empty()) {
    // printf("%f %d %f\n", rating, retailers[s], p);
    sum += rating * retailers[s] * p;
    // std::cout << sum << std::endl;

  } else {
    for (int i = 0; i < v[s].size(); i++) {
      if (!vis[v[s][i]]) {
        dfs(v[s][i], rating * (r / 100 + 1));
      }
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n >> p >> r;
  for (int i = 0; i < n; i++) {
    int num, a;
    cin >> num;
    if (num != 0) {
      while (num--) {
        cin >> a;
        v[i].push_back(a);
      }
    } else {
      cin >> a;
      retailers[i] = a;
      // retailers.push_back(retailer(i, a));
    }
  }
  // std::cout << r / 100 + 1 << std::endl;
  // std::cout << incre << std::endl;
  dfs(0, 1);
  printf("%.1f\n", sum);
  // std::cout << sum << std::endl;
  // for (int i = 0; i < n; i++) {
  //   printf("%d: ", i);
  //   for (int j = 0; j < v[i].size(); j++) {
  //     printf("%d%s", v[i][j], j == v[i].size() - 1 ? "\n" : " ");
  //   }
  // }

  fclose(stdin);
  return 0;
}