#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string b;
    int sum = 0;
    cin >> b;
    for (int i = 0; i < b.size(); i++) {
        sum += b[i] - '0';
    }
    string c = to_string(sum);
    for (int i = 0; i < c.size(); i++) {
        if (i == c.size() - 1) {
            std::cout << a[c[i] - '0'] << std::endl;
        } else {
            std::cout << a[c[i] - '0'] << " ";
        }
    }
    return 0;
}