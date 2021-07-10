#include <iostream>
using namespace std;
char letters[26][7][5];
int main() {
#ifdef ONLINE_JUDGE
#else
  freopen("1.txt", "r", stdin);
#endif
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 7; j++) {
      for (int k = 0; k < 5; k++) {
        cin >> letters[i][j][k];
      }
    }
  }

  string s;
  char a;
  a = getchar();
  a = getchar();
  s += a;
  // std::cout << a << std::endl;
  while (1) {
    a = getchar();
    if (a > 'Z' || a < 'A') {
      for (int i = 0; i < 7; i++) //行数的序号
      {
        for (int j = 0; j < s.length(); j++) // 字母的序号
        {
          int letter = s[j] - 'A';
          if (j == 0) {
            for (int k = 0; k < 5; k++) // 一个字母的一行的序号
            {
              printf("%c", letters[letter][i][k]);
            }
          } else {
            std::cout << " ";
            for (int k = 0; k < 5; k++) // 一个字母的一行的序号
            {
              printf("%c", letters[letter][i][k]);
            }
          }
        }
        printf("\n");
      }
      // std::cout << s << std::endl;
      s.clear();
      break;
    } else {
      s += a;
      // std::cout << s << std::endl;
    }
  }

  while (1) {
    a = getchar();
    // std::cout << a << std::endl;
    if (a == '\n') {
      break;
    } else if (a > 'Z' || a < 'A') {
      std::cout << "" << std::endl;
      for (int i = 0; i < 7; i++) //行数的序号
      {
        for (int j = 0; j < s.length(); j++) // 字母的序号
        {
          int letter = s[j] - 'A';
          if (j == 0) {
            for (int k = 0; k < 5; k++) // 一个字母的一行的序号
            {
              printf("%c", letters[letter][i][k]);
            }
          } else {
            std::cout << " ";
            for (int k = 0; k < 5; k++) // 一个字母的一行的序号
            {
              printf("%c", letters[letter][i][k]);
            }
          }
        }
        printf("\n");
      }
      // std::cout << s << std::endl;
      s.clear();
      continue;
    } else {
      s += a;
      // std::cout << s << std::endl;
    }
  }

  fclose(stdin);
  return 0;
}