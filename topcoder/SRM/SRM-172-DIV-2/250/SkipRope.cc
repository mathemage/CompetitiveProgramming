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

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

class SkipRope {
public:
  bool isBetter(int a, int b) {
    return (abs(a) < abs(b)) || (abs(a) == abs(b) && a > b);
  }
  vector <int> partners(vector <int> candidates, int height) {
    for (int & c : candidates)
      c -= height;

    int h0 = candidates[0];
    int h1 = candidates[1];
    if (isBetter(h1, h0))
      swap(h0, h1);

    FOR(i,2,candidates.size()) {
      int cur = candidates[i];
      if (isBetter(cur,h0)) {
        h1 = h0;
        h0 = cur;
      } else if (isBetter(cur,h1))
        h1 = cur;
    }
    if (h1 < h0)
      swap(h0, h1);
    return vector<int>{h0+height, h1+height};
  }
};

// 75.01/250 pts, done in two days
