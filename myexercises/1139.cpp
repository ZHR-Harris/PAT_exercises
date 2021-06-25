#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct cd {
  int c, d;
  cd(int c, int d) : c(c), d(d) {}
};
bool cmp(cd a, cd b) {
  if (a.c == b.c) {
    return a.d < b.d;
  } else {
    return a.c < b.c;
  }
}
const int maxn = 10000;
vector<int> v[maxn];
int p[maxn], n, m, k;

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    v[abs(stoi(a))].push_back(stoi(b));
    v[abs(stoi(b))].push_back(stoi(a));
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    vector<int> c_list;
    vector<cd> v2;
    cin >> a >> b;
    if (a * b < 0) // a,b是异性
    {
      for (int j = 0; j < v[abs(a)].size(); j++) {
        int c = v[abs(a)][j];
        if (a * c > 0) {                               // a,c是同性
          for (int k = 0; k < v[abs(c)].size(); k++) { //对于c的每一个朋友d
            int d = v[abs(c)][k];
            if (c * d < 0 &&
                find(v[abs(b)].begin(), v[abs(b)].end(), d) !=
                    v[abs(b)].end()) { //如果c，d是异性，并且d是b的朋友
              v2.push_back(cd(abs(c), abs(d)));
              // std::cout << c << " " << d << std::endl;
            }
          }
        }
      }
    } else { // a,b是同性
      for (int j = 0; j < v[abs(a)].size(); j++) {
        int c = v[abs(a)][j];
        if (a * c > 0) {                               // a,c是同性
          for (int k = 0; k < v[abs(c)].size(); k++) { //对于c的每一个朋友d
            int d = v[abs(c)][k];
            if (c * d > 0 &&
                find(v[abs(b)].begin(), v[abs(b)].end(), d) !=
                    v[abs(b)].end()) { //如果c，d是异性，并且d是b的朋友
              v2.push_back(cd(abs(c), abs(d)));
              // std::cout << c << "" << d << std::endl;
            }
          }
        }
      }
    }
    std::cout << v2.size() << std::endl;
    sort(v2.begin(), v2.end(), cmp);
    for (int j = 0; j < v2.size(); j++) {
      printf("%04d %04d\n", v2[j].c, v2[j].d);
    }
  }

  fclose(stdin);
  return 0;
}