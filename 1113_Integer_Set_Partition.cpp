#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<long> num;

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    std::cout << n % 2 << " ";
    for (int i = 0; i < n; i++) {
        long a;
        cin >> a;
        num.push_back(a);
    }
    sort(num.begin(), num.end());
    long s1 = 0, s2 = 0;
    for (int i = 0; i < n / 2; i++) {
        s1 += num[i];
    }
    for (int i = n / 2; i < n; i++) {
        s2 += num[i];
    }
    std::cout << abs(s1 - s2) << std::endl;

    fclose(stdin);
    return 0;
}