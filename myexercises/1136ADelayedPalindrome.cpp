#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct bign {
  int num[1010], len;
  bign() {
    fill(num, num + 1010, 0);
    len = 0;
  }
};

bign change(string n) {
  bign c;
  c.len = n.length();
  for (int i = n.length() - 1; i >= 0; i--) {
    c.num[c.len - i - 1] = n[i] - '0';
  }
  return c;
}

bign add(bign a, bign b) {
  bign c;
  int carry = 0;
  for (int i = 0; i < max(a.len, b.len); i++) {
    int sum = a.num[i] + b.num[i] + carry;
    c.num[c.len++] = sum % 10;
    carry = sum / 10;
  }
  if (carry != 0) {
    c.num[c.len++] = carry;
  }
  return c;
}

void print(bign a) {
  for (int i = a.len - 1; i >= 0; i--) {
    printf("%d", a.num[i]);
  }
}
bool isp(bign s) {
  if (s.len == 1) {
    return true;
  }

  for (int i = 0; i <= s.len / 2; i++) {
    if (s.num[i] != s.num[s.len - i - 1]) {
      return false;
    }
  }
  return true;
}

bign reverse(bign n) {
  for (int i = 0; i < n.len / 2; i++) {
    swap(n.num[i], n.num[n.len - i - 1]);
  }
  return n;
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  string s_;
  cin >> s_;
  bign s = change(s_);
  for (int i = 0; i < 10; i++) {
    bign s_rev = reverse(s);
    print(s);
    printf(" + ");
    print(s_rev);
    printf(" = ");
    s = add(s, s_rev);
    print(s);
    std::cout << "" << std::endl;
    if (isp(s)) {
      print(s);
      printf(" is a palindromic number.\n");
      break;
    }
    if (!isp(s) && i == 9) {
      std::cout << "Not found in 10 iterations." << std::endl;
    }
  }

  fclose(stdin);
  return 0;
}