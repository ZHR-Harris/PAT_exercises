#include <iostream>
#include <map>
using namespace std;
int main(int argc, char** argv)
{
    // freopen("1.txt", "r", stdin);
    map<int, int> color;
    int M, N, maxNum = 0, maxColor;
    cin >> M >> N;
    // std::cout << M << N << std::endl;
    // std::cout << "test1" << std::endl;
    while (N--) {
        // std::cout << "test2" << std::endl;
        for (int i = 0; i < M; i++) {
            // std::cout << M << std::endl;

            long color_num;
            cin >> color_num;
            map<int, int>::iterator it = color.find(color_num);
            if (it != color.end()) {
                it->second++;
            } else {
                color[color_num] = 1;
            }
        }
    }
    for (map<int, int>::iterator it = color.begin(); it != color.end(); it++) {
        if (it->second > maxNum) {
            maxNum = it->second;
            maxColor = it->first;
        }
    }
    std::cout << maxColor << std::endl;
    // fclose(stdin);
    return 0;
}
