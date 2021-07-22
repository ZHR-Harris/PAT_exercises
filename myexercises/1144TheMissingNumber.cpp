#include <climits>
#include <iostream>
using namespace std;
const long maxn = 1e5 + 10;
int num[maxn];
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    if (a > 0 && a < maxn) {
      num[a]++;
    }
  }
  for (int i = 1; i <= maxn; i++) {
    if (num[i] == 0) {
      std::cout << i << std::endl;
      break;
    }
  }

  fclose(stdin);
  return 0;
}