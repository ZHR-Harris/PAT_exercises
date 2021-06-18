#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, post[40], in[40];

struct node {
  node *l;
  node *r;
  int value, h;
  node(int v) : value(v), l(NULL), r(NULL), h(0){};
};
vector<node *> level[35];
node *create(int root, int start, int end) {
  if (start > end) {
    return NULL;
  }
  int i = start;
  while (i < end && in[i] != post[root]) {
    i++;
  }
  node *r = new node(post[root]);
  r->l = create(root - end + i - 1, start, i - 1);
  r->r = create(root - 1, i + 1, end);
  return r;
}
void print(node *r) {
  if (r == NULL) {
    return;
  }
  std::cout << r->value << std::endl;
  print(r->l);
  print(r->r);
}

void bfs(node *root) {
  queue<node *> q;
  q.push(root);
  level[root->h].push_back(root);
  while (!q.empty()) {
    node *now = q.front(), *l = now->l, *r = now->r;
    q.pop();
    if (l != NULL) {
      l->h = now->h + 1;
      level[l->h].push_back(l);
      // printf("l: %d \n", l->value);
      q.push(l);
    }
    if (r != NULL) {
      r->h = now->h + 1;
      level[r->h].push_back(r);
      // printf("r: %d \n", r->value);
      q.push(r);
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> post[i];
  }
  node *root = create(n - 1, 0, n - 1);

  bfs(root);

  printf("%d", level[0][0]->value);
  for (int i = 1; i < 35; i++) {
    if (i % 2 == 0) {
      for (int j = level[i].size() - 1; j >= 0; j--) {
        printf(" %d", level[i][j]->value);
      }
    } else {
      for (int j = 0; j < level[i].size(); j++) {
        printf(" %d", level[i][j]->value);
      }
    }
  }

  // print(root);
  fclose(stdin);
  return 0;
}