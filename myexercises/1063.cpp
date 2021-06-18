#include <iostream>
#include <set>
using namespace std;
int main(int argc, char** argv)
{
    // freopen("1.txt", "r", stdin);
    long N, M;
    cin >> N;
    set<int> num_set[N];
    for (int i = 0; i < N; i++) {
        cin >> M;
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            num_set[i].insert(num);
        }
    }
    int K;
    cin >> K;
    while (K--) {
        int set1, set2, nc = 0, nt = 0;
        cin >> set1 >> set2;
        set1--;
        set2--;
        for (set<int>::iterator it = num_set[set1].begin(); it != num_set[set1].end(); it++) {
            if (num_set[set2].find(*it) != num_set[set2].end()) { // find未找到返回end()
                nc++;
                // std::cout << *it << std::endl;
            }
        }
        nt = num_set[set1].size() + num_set[set2].size() - nc;
        // std::cout << nt << " " << nc << " " << num_set[set1].size() << " " << num_set[set2].size() << std::endl;
        printf("%.1f%%\n", (double)nc * 100 / nt); // %%表示输出'%'
    }
    // fclose(stdin);
    return 0;
}
