#include <iostream>
#include <vector>
using namespace std;
struct p {
  int id;
  bool boy;
  p(){};
  p(int id_, bool boy_) {
    id = id_;
    boy = boy_;
  }
};
const int maxn = 5000;
int 
vector<p> v[maxn];

int n, m, k;
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    p p1, p2;
    cin >> a >> b;
    if (a < 0) {
      p1 = p(abs(a), false);
    } else {
      p1 = p(a, true);
    }
    if (b < 0) {
      p2 = p(abs(b), false);
    } else {
      p2 = p(b, true);
    }
    v[p1.id].push_back(p2);
    v[p2.id].push_back(p1);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < v[abs(a)].size(); j++) {
      p c = v[abs(a)][j];
      }
  }

  fclose(stdin);
  return 0;
}