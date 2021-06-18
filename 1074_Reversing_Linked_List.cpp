#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 0x3ffffff;
const int maxn = 100020;
struct Node {
    int address, data, next, level;
    Node()
        : level(INF) {};
} node[maxn];

bool cmp(Node n1, Node n2)
{
    return n1.level < n2.level;
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif

    int s, n, k;
    cin >> s >> n >> k;
    for (int i = 0; i < n; i++) {
        int address, data, next;
        cin >> address >> data >> next;
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    int p = s, x = 0;
    while (p != -1) {
        node[p].level = x;
        x++;
        // std::cout << p << " " << node[p].data << " " << node[p].next << " " << node[p].level << std::endl;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    for (int i = 0; i + k <= x; i += k) {
        reverse(node + i, node + i + k);
    }
    for (int i = 0; i < x - 1; i++) {
        printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
        // std::cout << node[i].address << " " << node[i].data << " " << node[i + 1].address << std::endl;
    }
    printf("%05d %d -1\n", node[x - 1].address, node[x - 1].data);

    // std::cout << node[x - 1].address << " " << node[x - 1].data << " " << -1 << std::endl;
    fclose(stdin);
    return 0;
}