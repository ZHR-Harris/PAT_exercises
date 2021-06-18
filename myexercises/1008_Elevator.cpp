#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
    // freopen("1.txt", "r", stdin);
    int num;
    int from_f = 0, to_f = 0, time = 0;
    cin >> num;
    while (num--) {
        from_f = to_f;
        cin >> to_f;
        int diff = to_f - from_f;
        // std::cout << "diff:" << diff << std::endl;
        if (diff < 0) {
            time += abs(4 * diff);
            time += 5;
            // std::cout << "time:" << time << std::endl;
        } else {
            time += 6 * diff;
            time += 5;
            // std::cout << "time:" << time << std::endl;
        }
    }
    std::cout << time << std::endl;
    // fclose(stdin);
    return 0;
}
