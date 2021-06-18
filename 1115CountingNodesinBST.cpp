#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1010;
int n, a[maxn], maxh, n1, n2;
struct node {
  int v, h;
  node *l;
  node *r;
  node(int value, int height) : v(value), l(NULL), r(NULL), h(height){};
};
void insert(node *&root, int v, int h) {
  if (root == NULL) {
    root = new node(v, h);
    maxh = max(maxh, h);
    return;
  }
  if (v <= root->v) {
    insert(root->l, v, ++h);
  } else {3
    insert(root->r, v, ++h);
  }
}

void bfs(node *root) {
  queue<node *> q;
  q.push(root);
  while (!q.empty()) {
    node *now = q.front();
    q.pop();
    // printf("level %d: %d\n", now->h, now->v);
    if (now->h == maxh) {
      n1++;
    } else if (now->h == maxh - 1) {
      n2++;
    }
    if (now->l != NULL) {
      q.push(now->l);
    }
    if (now->r != NULL) {
      q.push(now->r);
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n;
  node *root = NULL;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    insert(root, v, 0);
  }
  bfs(root);
  printf("%d + %d = %d\n", n1, n2, n1 + n2);
  fclose(stdin);
  return 0;
}