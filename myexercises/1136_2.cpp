#include <algorithm>
#include <iostream>
using namespace std;
string rev(string s) {
  reverse(s.begin(), s.end());
  return s;
}

string add(string s1, string s2) {
  string s = s1;
  int carry = 0;
  for (int i = s1.length() - 1; i >= 0; i--) {
    s[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
    carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
  }
  if (carry > 0) {
    s = '1' + s;
  }
  return s;
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  if (s == rev(s)) {
    cout << s << " is a palindromic number.\n";
    return 0;
  } //最开始一个的情况要考虑
  for (int i = 0; i < 10; i++) {
    string sum = add(s, rev(s));
    printf("%s + %s = %s\n", s.c_str(), rev(s).c_str(), sum.c_str());
    if (sum == rev(sum)) {
      printf("%s is a palindromic number.\n", sum.c_str());
      break;
    }
    if (sum != rev(sum) && i == 9) {
      printf("Not found in 10 iterations.\n");
    }
    s = sum;
  }

  fclose(stdin);
  return 0;
}