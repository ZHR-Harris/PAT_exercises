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
  for (int cnt = 1; cnt < n; cnt++) {
    string t;
    for (int i = 0; i < s.length(); i = j) {
      for (j = i; j < s.length() && s[j] == s[i]; j++)
        // std::cout << j << std::endl;
        ;
      t += s[i] + to_string(j - i);
    }
    s = t;
  }
  cout << s;

  fclose(stdin);

  return 0;
}