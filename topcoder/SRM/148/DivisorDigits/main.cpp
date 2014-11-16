#include<cassert>
#include<string>
using namespace std;

class DivisorDigits {
public:
  int howMany(int number) {
    int count = 0;
    for (char d : to_string(number)) {
      count += (d == '0') ? 0 : (number % (d - '0') == 0);
    }
    return count;
  }
};

int main() {
  DivisorDigits dd;
  assert ( dd.howMany(12345) == 3 );
  assert ( dd.howMany(33333) == 5 );
}
