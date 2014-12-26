#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <cctype>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

class SimpleCalculator {
public:
  int calculate(string input) {
    int a = 0, b = 0;
    char op = '.';
    for (char c : input) {
      if (isdigit(c)) {
        if (op == '.') {
          a *= 10;
          a += c - '0';
        } else {
          b *= 10;
          b += c - '0';
        }
      } else {
        op = c;
      }
    }

    int result;
    switch (op) {
      case '+':
        result = a + b;
        break;
      case '-':
        result = a - b;
        break;
      case '*':
        result = a * b;
        break;
      case '/':
        result = a / b;
        break;
    }
    return result;
  }
};

// 241.28 / 250
