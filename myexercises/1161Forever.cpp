#include <cmath>
#include <iostream>
using namespace std;
int n, k, m;
bool isPrime(int n) {
  if (n <= 1) {
    return false;
  } else {
    for (int i = 2; i <= (int)sqrt(1.0 * n); i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n;
  for (int index = 1; index <= n; index++) {
    printf("Case %d\n", index);
    cin >> k >> m;
    
  }

  fclose(stdin);
  return 0;
}