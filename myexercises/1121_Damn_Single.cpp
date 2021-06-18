#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 100100;
struct p {
  int CoupleID;
  bool hascome;
  p(int id) : CoupleID(id), hascome(false){};
};
p *ps[maxn];

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif // ONLINE_JUDGE
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int id1, id2;
    cin >> id1 >> id2;
    p *p1 = new p(id2);
    p *p2 = new p(id1);
    ps[id1] = p1;
    ps[id2] = p2;
  }
  int m, res[maxn], cnt = 0;
  fill(res, res + maxn, -1);
  cin >> m;
  int id[m];
  for (int i = 0; i < m; i++) {
    cin >> id[i];
    ps[id[i]]->hascome = true;
  }
  for (int i = 0; i < m; i++) {
    int coupleID = ps[id[i]]->CoupleID;
    if (coupleID != -1 && ps[coupleID]->hascome) {
      res[cnt++] = id[i];
    }
  }
  sort(res, res + maxn);
  cout << cnt << endl;
  cout << res[0];
  for (int i = 1; i < cnt; i++) {
    cout << " " << res[i];
  }
  cout << "" << endl;
  fclose(stdin);
  return 0;
}