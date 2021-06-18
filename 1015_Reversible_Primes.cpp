#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) {
    return false;
  } else {
    for (int i = 2; i <= (int)sqrt(n); i++) {
      if (n % i == 0) {
        return false;
      }
    }
  }
  return true;
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  int n, d;
  while (scanf("%d", &n) != EOF) {
    if (n < 0) {
      break;
    }
    cin >> d;
    if (isPrime(n) == false) {
      std::cout << "No" << std::endl;
      continue;
    }
    int num[500], len = 0;
    do {
      num[len++] = n % d;
      n /= d;
    } while (n != 0);
    int rev_n = 0;
    for (int i = 0; i < len; i++) {
      rev_n = rev_n * d + num[i];
    }
    printf(isPrime(rev_n) ? "Yes\n" : "No\n");
  }

  fclose(stdin);
  return 0;
}