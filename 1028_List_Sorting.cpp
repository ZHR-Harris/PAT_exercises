#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct stu {
    int grade;
    string id, name;
};
vector<stu> Ss;
bool cmp1(stu stu1, stu stu2)
{
    return stu1.id < stu2.id;
}
bool cmp2(stu stu1, stu stu2)
{
    if (stu1.name != stu2.name) {
        return stu1.name < stu2.name;
    } else {
        return stu1.id < stu2.id;
    }
}
bool cmp3(stu stu1, stu stu2)
{
    if (stu1.grade != stu2.grade) {
        return stu1.grade < stu2.grade;
    } else {
        return stu1.id < stu2.id;
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        stu s;
        cin >> s.id >> s.name >> s.grade;
        Ss.push_back(s);
    }
    switch (c) {
    case 1:
        sort(Ss.begin(), Ss.end(), cmp1);
        for (int i = 0; i < Ss.size(); i++) {
            std::cout << Ss[i].id << " " << Ss[i].name << " " << Ss[i].grade << std::endl;
        }
        break;
    case 2:
        sort(Ss.begin(), Ss.end(), cmp2);
        for (int i = 0; i < Ss.size(); i++) {
            std::cout << Ss[i].id << " " << Ss[i].name << " " << Ss[i].grade << std::endl;
        }
        break;
    case 3:
        sort(Ss.begin(), Ss.end(), cmp3);
        for (int i = 0; i < Ss.size(); i++) {
            std::cout << Ss[i].id << " " << Ss[i].name << " " << Ss[i].grade << std::endl;
        }

        break;
    }
    fclose(stdin);
    return 0;
}