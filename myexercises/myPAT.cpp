#include <iostream>
using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif

  fclose(stdin);
  return 0;
}