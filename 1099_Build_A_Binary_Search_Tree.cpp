#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct node {
  int index, data;
  node *l;
  node *r;
  node() : l(NULL), r(NULL){};
};
int n;
const int maxn = 110;
int levelorder[maxn];

void insert(node *root) {
  int lIndex, rIndex;
  cin >> lIndex >> rIndex;
  if (lIndex != -1 && rIndex != -1) {
    root->l = new node;
    root->r = new node;
    insert(root->l);
    insert(root->r);
  } else if (lIndex == -1 && rIndex != -1) {
    root->r = new node;
    insert(root->r);
  } else if (lIndex != -1 && rIndex == -1) {
    root->l = new node;
    insert(root->l);
  }
}
int a = 0;

void inorder(node *root, int values[]) {
  if (root == NULL) {
    return;
  }
  inorder(root->l, values);
  root->data = values[a++];
  inorder(root->r, values);
}

queue<node *> q;
int b = 0;
void levelOrder(node *root) {
  q.push(root);
  // std::cout << root->data;
  // if (root->l != NULL) {
  //   q.push(root->l);
  // }
  // if (root->r != NULL) {
  //   q.push(root->r);
  // }
  while (!q.empty()) {
    node *now = q.front();
    q.pop();
    if (now->l != NULL) {
      q.push(now->l);
    }
    if (now->r != NULL) {
      q.push(now->r);
    }
    levelorder[b++] = now->data;
    // std::cout << " " << now->data;
  }
}

int main(int argc, char **argv) {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif // DEBUG
  cin >> n;
  int values[n];
  node *root = new node;
  insert(root);
  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }
  sort(values, values + n);
  inorder(root, values);
  levelOrder(root);
  std::cout << levelorder[0];
  for (int i = 1; i < n; i++) {
    std::cout << " " << levelorder[i];
  }
  std::cout << "" << std::endl;
  fclose(stdin);
  return 0;
}
