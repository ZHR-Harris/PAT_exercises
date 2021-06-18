#include <cstdio>
#include <iostream>
using namespace std;
struct node {
  int data;
  node *lchild;
  node *rchild;
  node() : lchild(NULL), rchild(NULL){};
};

node *root = NULL;
const int maxn = 1010;
int n, keys[maxn];
int treePreorder[maxn], a = 0, mirrorPreorder[maxn], b = 0;
int treePostorder[maxn], c = 0, mirrorPostorder[maxn], d = 0;

void insert(node *&root, int data) {
  if (root == NULL) {
    root = new node;
    root->data = data;
  } else if (root->data > data) {
    insert(root->lchild, data);
  } else {
    // std::cout << "/* message */" << data << std::endl;
    insert(root->rchild, data);
  }
}

void DFS(node *root) {
  if (root == NULL) {
    return;
  }
  treePreorder[a++] = root->data;
  DFS(root->lchild);
  DFS(root->rchild);
  treePostorder[c++] = root->data;
}

void mirrorDFS(node *root) {
  if (root == NULL) {
    return;
  }
  mirrorPreorder[b++] = root->data;
  mirrorDFS(root->rchild);
  mirrorDFS(root->lchild);
  mirrorPostorder[d++] = root->data;
}

bool compare(int treePreorder[], int mirrorPreorder[]) {
  for (int i = 0; i < n; i++) {
    if (treePreorder[i] != mirrorPreorder[i]) {
      return false;
    }
  }
  return true;
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif // DEBUG
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> keys[i];
    insert(root, keys[i]);
  }
  // for (int i = 0; i < n; i++) {
  //   std::cout << keys[i] << endl;
  // }
  DFS(root);
  mirrorDFS(root);
  // for (int i = 0; i < n; i++) {
    // std::cout << treePostorder[i] << " " << keys[i] << std::endl;
    // std::cout << mirrorPostorder[i] << " " << keys[i] << std::endl;
  // }
  if (compare(treePreorder, keys)) {
    std::cout << "YES" << std::endl;
    std::cout << treePostorder[0];
    for (int i = 1; i < n; i++) {
      std::cout << " " << treePostorder[i];
    }
    std::cout << "" << std::endl;
  } else if (compare(mirrorPreorder, keys)) {
    std::cout << "YES" << std::endl;
    std::cout << mirrorPostorder[0];
    for (int i = 1; i < n; i++) {
      std::cout << " " << mirrorPostorder[i];
    }
    std::cout << "" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  fclose(stdin);
  return 0;
}