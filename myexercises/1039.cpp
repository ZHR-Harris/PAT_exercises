#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char** argv)
{
    // freopen("1.txt", "r", stdin);
    map<string, vector<int> > stu_course;
    int N, K;
    cin >> N >> K;
    while (K--) {
        int index, stu_num;
        cin >> index >> stu_num;
        for (int i = 0; i < stu_num; i++) {
            string name;
            cin >> name;
            stu_course[name].push_back(index);
        }
    }
    while (N--) {
        string name;
        cin >> name;
        std::cout << name << " " << stu_course[name].size();
        sort(stu_course[name].begin(), stu_course[name].end());
        for (vector<int>::iterator it = stu_course[name].begin(); it != stu_course[name].end(); it++) {
            std::cout << " " << *it;
        }
        std::cout << "" << std::endl;
    }
    // fclose(stdin);
    return 0;
}
