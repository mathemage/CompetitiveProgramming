#include <iostream>
#include<sstream>
using namespace std;

class Time {
  static const int SEC_PER_MIN = 60;
  static const int SEC_PER_HOUR = 60 * SEC_PER_MIN;
  static const int SEC_PER_DAY = 24 * SEC_PER_HOUR;

public:
  string whatTime(int total) {
    total %= SEC_PER_DAY;
    int H = total / SEC_PER_HOUR;
    total %= SEC_PER_HOUR;
    int M = total / SEC_PER_MIN;
    total %= SEC_PER_MIN;

    stringstream result;
    result << H << ":" << M << ":" << total;
    return result.str();
  }
};

int main() {
  Time time;
  cout << time.whatTime(0) << endl;
  cout << time.whatTime(3661) << endl;
  cout << time.whatTime(5436) << endl;
  cout << time.whatTime(86399) << endl;
}
