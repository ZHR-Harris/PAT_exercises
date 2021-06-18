
// Look-and-say sequence is a sequence of integers as the following:

// D, D1, D111, D113, D11231, D112213111, ...
// where D is in [0, 9] except 1. The (n+1)st number is a kind of description of the nth number. For example, the 2nd number means that there is one D in the 1st number, and hence it is D1; the 2nd number consists of one D (corresponding to D1) and one 1 (corresponding to 11), therefore the 3rd number is D111; or since the 4th number is D113, it consists of one D, two 1's, and one 3, so the next number must be D11231. This definition works for D = 1 as well. Now you are supposed to calculate the Nth number in a look-and-say sequence of a given digit D.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // freopen("1.txt", "r", stdin);
    int n;
    string d, old_str, new_str;
    cin >> d >> n;
    old_str = d;
    while (--n) {
        // std::cout << n << std::endl;
        string first = d;
        // std::cout << first << std::endl;
        new_str.clear();
        int count = 1;
        for (int i = 1; i < old_str.length(); i++) {
            // std::cout << i << std::endl;
            if (old_str[i] == first[0]) {
                count++;
                // std::cout << first << " " << count << std::endl;
            } else {
                new_str += first;
                new_str += to_string(count);
                first.clear();
                first = old_str[i];
                count = 1;
                // std::cout << first << " " << count << std::endl;
            }
        }
        new_str += old_str[old_str.length() - 1];
        new_str += to_string(count);
        // std::cout << old_str << " " << new_str << std::endl;
        // std::cout << new_str << std::endl;
        old_str = new_str;
    }
    std::cout << new_str << std::endl;
    // fclose(stdin);
    return 0;
}