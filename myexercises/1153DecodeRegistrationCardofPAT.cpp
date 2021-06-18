#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct pat {
  string level, card, site, date, num;
  int score;
  pat(string card, string level, string site, string date, string num,
      int score)
      : card(card), level(level), site(site), date(date), num(num),
        score(score){};
};

struct query3 {
  string site;
  int num;
  query3(string site, int num) : site(site), num(num){};
};

bool cmp1(pat a, pat b) {
  return a.score != b.score ? a.score > b.score : a.card < b.card;
}

bool cmp2(query3 a, query3 b) {
  return a.num != b.num ? a.num > b.num : a.site < b.site;
}

vector<pat> records;
int n, m;

int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  cin >> n >> m;
  string card;
  int score;
  for (int i = 0; i < n; i++) {
    cin >> card >> score;
    string site = card.substr(1, 3), date = card.substr(4, 6),
           num = card.substr(10, 3);
    records.push_back(pat(card, card.substr(0, 1), site, date, num, score));
  }
  int type;
  string term;
  for (int j = 0; j < m; j++) {
    cin >> type >> term;
    vector<pat> level;
    int sum = 0, cnt = 0;
    vector<query3> date;
    map<string, int> mp;
    switch (type) {
    case 1:
      for (auto i = records.begin(); i != records.end(); i++) {
        if (i->level == term) {
          level.push_back(*i);
        }
      }
      sort(level.begin(), level.end(), cmp1);
      printf("Case %d: %d %s\n", type, type, term.c_str());
      if (level.empty()) {
        printf("Case 4: %d %s\nNA\n", type, term.c_str());
        break;
      }
      for (auto i = level.begin(); i != level.end(); i++) {
        std::cout << i->card << " " << i->score << std::endl;
      }
      break;
    case 2:
      for (auto i = records.begin(); i != records.end(); i++) {
        if (i->site == term) {
          cnt++;
          sum += i->score;
        }
      }
      if (cnt == 0) {
        printf("Case 4: %d %s\nNA\n", type, term.c_str());
        break;
      }

      printf("Case %d: %d %s\n%d %d\n", type, type, term.c_str(), cnt, sum);
      break;
    case 3:
      for (auto i = records.begin(); i != records.end(); i++) {
        if (i->date == term) {
          if (mp.find(i->site) == mp.end()) {
            mp[i->site] = 1;
          } else {
            mp.find(i->site)->second++;
          }
        }
      }
      for (auto i = mp.begin(); i != mp.end(); i++) {
        date.push_back(query3(i->first, i->second));
      }
      if (date.empty()) {
        printf("Case 4: %d %s\nNA\n", type, term.c_str());
        break;
      }
      sort(date.begin(), date.end(), cmp2);
      printf("Case %d: %d %s\n", type, type, term.c_str());
      for (auto i = date.begin(); i != date.end(); i++) {
        std::cout << i->site << " " << i->num << std::endl;
      }
      break;
    }
  }

  fclose(stdin);
  return 0;
}