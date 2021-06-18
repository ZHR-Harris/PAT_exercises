#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct car {
  string id;
  int in_time, out_time, duration;
};
vector<car> cars;
vector<string> max_id;
// map<string, car> mp;
int n, k, max_time = -1;
// bool cmp1(){

// }

int convert(int h, int m, int s) { return 3600 * h + 60 * m + s; }

void filter() {
  for (int i = 0; i < cars.size(); i++) {
    std::cout << cars[i].id << " " << cars[i].in_time << " " << cars[i].out_time
              << " " << cars[i].duration << std::endl;
    if (cars[i].in_time == -1 || cars[i].out_time == -1) {
      cars.erase(cars.begin() + i);
    } else {
      cars[i].duration = cars[i].out_time - cars[i].in_time;
      if (cars[i].duration > max_time) {
        max_time = cars[i].duration;
        max_id.clear();
        max_id.push_back(cars[i].id);
      }
    }
  }
}

int find(string id) {
  for (int i = 0; i < cars.size(); i++) {
    if (cars[i].id == id) {
      return i;
    }
  }
  return -1;
}

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string id, state;
    int h, m, s;

    cin >> id;
    scanf("%d:%d:%d", &h, &m, &s);
    cin >> state;
    int index = find(id);
    if (index == -1) {
      car c;
      c.id = id;
      c.in_time = -1;
      c.out_time = -1;
      if (state == "in") {
        c.in_time = convert(h, m, s);
        // std::cout << c.in_time << std::endl;
      } else {
        c.out_time = convert(h, m, s);
        // std::cout << c.out_time << std::endl;
      }
      cars.push_back(c);
    } else {
      if (state == "in") {
        cars[index].in_time = convert(h, m, s);
        // std::cout << c.in_time << std::endl;
      } else {
        cars[index].out_time = convert(h, m, s);
        // std::cout << c.out_time << std::endl;
      }
    }
  }
  filter();
  for (int i = 0; i < k; i++) {
    int query, num = 0;
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    query = convert(h, m, s);
    for (int i = 0; i < cars.size(); i++) {
      if (cars[i].in_time <= query && cars[i].out_time >= query) {
        num++;
      }
    }
    std::cout << num << std::endl;
  }
  sort(max_id.begin(), max_id.end());
  for (int i = 0; i < max_id.size(); i++) {
    std::cout << max_id[i] << " ";
    int h = max_time / 3600, m = (max_time % 3600) / 60, s = max_time % 60;
    printf("%2d:%2d:%2d\n", h, m, s);
  }
  std::cout << "test:" << std::endl;
  int t_ = convert(12, 23, 42) - convert(05, 10, 33);
  int h = t_ / 3600, m = (t_ % 3600) / 60, s = t_ % 60;
  // std::cout << convert(12, 23, 42) << " " << convert(05, 10, 33) << " " << t_
  // << std::endl;
  std::cout << h << m << s << std::endl;
  printf("%2d:%2d:%2d\n", h, m, s);
  fclose(stdin);
  return 0;
}