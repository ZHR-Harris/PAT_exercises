#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int value[maxn], preorder[maxn+1], k = 0 , n;

void dfs(int root){
    if (root > n)
    {
        return;
    }
    dfs(root*2);
    preorder[root] = value[k++];
    dfs(root*2+1);
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif
cin>>n;
for (int i = 0; i < n; i++)
{
    cin >> value[i];
}
sort(value, value+n);
dfs(1);
std::cout << preorder[1];
for (int i = 2; i <= n; i++)
{
std::cout << " "<< preorder[i];
}
std::cout << "" << std::endl;

    fclose(stdin);
    return 0;
}