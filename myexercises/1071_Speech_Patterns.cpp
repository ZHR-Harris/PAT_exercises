#include <cctype>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    // freopen("1.txt", "r", stdin);
    string s, word;
    map<string, int> cnt;
    getline(cin, s);
    for (int i = 0, l = s.size(); i < l; i++) {
        word.clear();
        while (i < l && isalnum(tolower(s[i]))) {
            word.push_back(tolower(s[i]));
            i++;
        }
        if (word == "") {
            continue;
        }

        if (cnt.find(word) != cnt.end()) {
            cnt[word]++;
        } else {
            cnt[word] = 1;
        }
    }
    int max = -1;
    string max_word;
    for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        // std::cout << it->first << " " << it->second << std::endl;
        if (it->second > max) {
            max = it->second;
            max_word = it->first;
            // std::cout << it->first << std::endl;
        }
    }
    std::cout << max_word << " " << max << std::endl;
    // fclose(stdin);
    return 0;
}