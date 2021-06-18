#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
    // freopen("1.txt", "r", stdin);
    int num;
    string inID, outID, minTime = "25:70:70", maxTime = "00:00:00";
    cin >> num;
    while (num--) {
        string id, in, out;
        cin >> id >> in >> out;
        if (in < minTime) {
            minTime = in;
            inID = id;
        }
        if (out > maxTime) {
            maxTime = out;
            outID = id;
        }
    }
    std::cout << inID << " " << outID << std::endl;
    // fclose(stdin);
    return 0;
}
