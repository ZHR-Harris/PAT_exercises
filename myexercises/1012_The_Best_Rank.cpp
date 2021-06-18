#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3fffffff;
struct student {
    int id;
    int grade[4];
    int rank[4];
};
vector<student> stu;
int n, m, c; // course id
bool cmp1(student stu1, student stu2)
{
    return stu1.grade[c] > stu2.grade[c];
}
bool cmp2(student stu1, student stu2)
{
    return stu1.id < stu2.id;
}

void ranking()
{
    stu[0].rank[c] = 1;
    for (int i = 1; i < n; i++) {
        stu[i].rank[c] = i + 1;
        if (stu[i].grade[c] == stu[i - 1].grade[c]) {
            stu[i].rank[c] = stu[i - 1].rank[c];
        }
    }
}

int binary_search(int id)
{
    int l = 0, r = n - 1; // binary search for the query id
    while (l <= r) {
        int mid = (l + r) / 2;
        if (stu[mid].id == id) {
            return mid;
        } else if (stu[mid].id < id) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int search(int id)
{
    for (int i = 0; i < n; i++) {
        if (stu[i].id == id) {
            return i;
        }
    }
    return -1;
}

int main()
{
    // freopen("1.txt", "r", stdin);
    char a[] = { 'A', 'C', 'M', 'E' };
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        student s;
        cin >> s.id >> s.grade[1] >> s.grade[2] >> s.grade[3];
        // std::cout << s.id << std::endl;
        s.grade[0] = s.grade[3] + s.grade[1] + s.grade[2];
        stu.push_back(s);
    }
    for (c = 0; c < 4; c++) {
        sort(stu.begin(), stu.end(), cmp1);
        ranking();
    }
    // sort(stu.begin(), stu.end(), cmp2);

    while (m--) {
        int id;
        cin >> id;
        // int mid = binary_search(id);
        // std::cout << "/* message */" << std::endl;
        int mid = search(id);

        if (mid == -1) {
            std::cout << "N/A" << std::endl;
        } else {
            int max_rank = INF, index = 0;
            for (int i = 0; i < 4; ++i) {
                if (stu[mid].rank[i] < max_rank) {
                    max_rank = stu[mid].rank[i];
                    index = i;
                }
            }

            std::cout << max_rank << " " << a[index] << std::endl;
        }
    }

    // fclose(stdin);
    return 0;
}