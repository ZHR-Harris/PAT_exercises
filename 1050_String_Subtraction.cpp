#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int max_len = 100000;
bool marked[1000] = {false};
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  char s1[max_len], s2[max_len];
  fgets(s1, max_len, stdin);
  fgets(s2, max_len, stdin);
  for (int i = 0; i < strlen(s2); i++) {
    marked[s1[i]] = true;
  }
  for (int i = 0; i < strlen(s1); i++) {
    if (marked[s1[i]]) {
      continue;
    }
    putchar(s1[i]);
  }

  fclose(stdin);
  return 0;
}