#include <iostream>
#include <math.h>
#include <string>
using namespace std;
bool isPrime(int num) {
  if (num <= 1) {
    return false;
  } else {
    for (int i = 2; i <= sqrt(num); i++) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  }
}

int main(int argc, char **argv) {
  int l, k;
  string s;
  cin >> l >> k >> s;
  for (int i = 0; i <= l - k; i++) {
    string num = s.substr(i, k);
    int sum = stoi(num);
    if (isPrime(sum)) {
      std::cout << num << std::endl;
      // fclose(stdin);
      return 0;
    }
  }
  std::cout << "404\n";
  return 0;
}
