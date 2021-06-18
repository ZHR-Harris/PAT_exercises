#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, L;
const int maxn = 1000;
int BFS(vector<int> p[], int id)
{
    int cnt = 0;
    int level = 0;
    queue<int> q;
    bool vis[maxn + 1] = { false };
    q.push(id);
    vis[id] = true;
    while (!q.empty() && level++ <= L) {
        for (int i = 0, u, l = (int)q.size(); i < l; i++) {
            // for (int i = 0; i < (int)q.size(); i++) {
            u = q.front();
            cnt++;
            for (int v : p[u]) {
                if (!vis[v]) {
                    // cnt++;
                    q.push(v);
                    vis[v] = true;
                }
            }
            q.pop();
        }
    }
    return cnt - 1;
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif
    cin >> n >> L;
    vector<int> p[n + 1];
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            p[num].push_back(i);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int id;
        cin >> id;
        std::cout << BFS(p, id) << std::endl;
    }
    fclose(stdin);
    return 0;
}