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

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

class ClockWalk {
public:
  int finalPosition(string flips) {
    int result = 0;
    int n = 1;
    for (char f : flips) {
      result += (f == 'h') ? n : -n;
      result %= 12;
      n++;
      MSG(result) MSG(n)
    }

    return (result > 0) ? result : result + 12;
  }
};

// 225.99/250
