#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif
    int num, n;
    vector<int> div;
    cin >> num;

    while (num != 1) {
        int temp;
        for (int i = 9; i > 1; i--) {
            if (num % i == 0) {
                div.push_back(i);
                temp = i;
                break;
            }
        }
        num /= temp;
    }
    for (int i = 0; i < div.size(); i++) {
        std::cout << div[i] << std::endl;
    }

    /* your code */
    fclose(stdin);
    return 0;
}