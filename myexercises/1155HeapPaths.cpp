#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;
int n, tree[maxn];
vector<int> path;
void dfs(int index) {
  if (index * 2 > n)
  // 判断是否为叶节点，只要判断当前节点的左节点*2是否大于n，无需判断右节点
  {
    if (index <= n) //判断是否为空节点
    {
      //如果是叶节点
      for (int i = 0; i < path.size(); i++) {
        printf("%d%s", path[i], i == path.size() - 1 ? "\n" : " ");
      }
    }
  } else //非叶节点
  {
    path.push_back(tree[2 * index + 1]);
    dfs(2 * index + 1);
    path.pop_back();
    path.push_back(tree[2 * index]);
    dfs(2 * index);
    path.pop_back();
  }
}

int main() {
// #ifdef ONLINE_JUDGE
// #else
//   freopen("1.txt", "r", stdin);
// #endif
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> tree[i];
  }
  path.push_back(tree[1]);
  dfs(1);
  bool isMin = true, isMax = true;
  for (int i = 2; i <= n; i++) {
    if (tree[i / 2] > tree[i]) {
      isMin = false;
    } else if (tree[2 / i] < tree[i]) {
      isMax = false;
    }
  }
  if (isMin) {
    std::cout << "Min Heap" << std::endl;
  } else if (isMax) {
    std::cout << "Max Heap" << std::endl;
  } else {
    std::cout << "Not Heap" << std::endl;
  }
  // fclose(stdin);
  return 0;
}