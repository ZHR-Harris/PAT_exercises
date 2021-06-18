#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, s;
struct node {
    int id, w, childn;
    node() {};
    node(int id, int w, int childn)
        : id(id)
        , w(w)
        , childn(childn) {};
};
bool cmp(vector<int> path1, vector<int> path2)
{
    for (int i = 0; i <= min(path1.size(),path2.size()); i++)
    {
        if (path1[i] != path2[i])
        {
            return path1[i] > path2[i];
        }
    }
    return true;
}

int sum = 0;
vector<vector<int> > paths;

void DFS(vector<node> children[], int id, node all[], int sum, vector<int> path)
{
    sum += all[id].w;
    path.push_back(all[id].w);
    // std::cout << sum << std::endl;
    if (children[id].size() == 0) {
        if (sum == s) {
            paths.push_back(path);
        }
        return;
    }
    for (node n : children[id]) {
        DFS(children, n.id, all, sum, path);
    }
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif
    cin >> n >> m >> s;
    node all[n];
    vector<node> children[n];
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        all[i] = node(i, w, 0);
    }
    for (int i = 0; i < m; i++) {
        int id, num;
        cin >> id >> num;
        for (int i = 0; i < num; i++) {
            int childnum;
            cin >> childnum;
            children[id].push_back(all[childnum]);
        }
    }
    vector<int> path;
    DFS(children, 0, all, 0, path);
    sort(paths.begin(), paths.end(), cmp);
    // std::cout << paths.size() << std::endl;
    for (auto path : paths) {
        int n = 0;
        for (auto id : path) {
            n++;
            if (n != path.size())
            {
                std::cout << id << " ";
            }else{
                n = 0;
                std::cout << id<< std::endl;
            }
        }
    }
    fclose(stdin);
    return 0;
}