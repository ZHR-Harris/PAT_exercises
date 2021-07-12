#include <algorithm>
#include <iostream>
using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  string s;
  int n, j;
  cin >> s >> n;
  for (int index = 1; index < n; index++) {
    string t;
    for (int i = 0; i < s.length(); i = j) {
      for (j = i; j < s.length(); j++)
        if (s[j] == s[i]) {
          continue;
        } else {
          break;
        }

        // std::cout << j << std::endl;
        ;
      t += s[i] + to_string(j - i);
    }
    s = t;
  }
  std::cout << s << std::endl;
  fclose(stdin);
  return 0;
}