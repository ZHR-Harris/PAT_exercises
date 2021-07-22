#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
struct node {
  int add, data, next;
};
node list[maxn];
int initial, n, k, cnt;

void print(int min, int max) {
  int now = list[initial].add;
  while (now != -1) {
    int data = list[now].data, add = list[now].add, next = list[now].next;
    if (data >= min && data <= max) {
      cnt++;
      if (cnt == 1) {
        printf("%05d %d ", add, data);
      } else {
        printf("%05d\n%05d %d ", add, add, data);
      }
    }
    now = next;
  }
}
void test() {
  int now = list[initial].add;
  while (now != -1) {
    int data = list[now].data, add = list[now].add, next = list[now].next;
    printf("%05d %d %05d\n", add, data, next);
    now = next;
  }
}
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> initial >> n >> k;
  for (int i = 0; i < n; i++) {
    int add;
    cin >> add;
    // std::cout << add << std::endl;
    list[add].add = add;
    cin >> list[add].data >> list[add].next;
  }
  // test();
  print(-1e5, -1);
  print(0, k);
  print(k + 1, 1e5);
  printf("%d\n", -1);
  fclose(stdin);
  return 0;
}