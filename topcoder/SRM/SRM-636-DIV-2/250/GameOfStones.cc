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

class GameOfStones {
public:
  int count(vector <int> stones) {
    int result = 0;
    int h = accumulate(ALL(stones),0);
    int sz = stones.size();
    MSG(h) MSG(sz)
    if (h % sz != 0)
      return -1;
    else
      h /= sz;
    MSG(h)

    for (int s : stones) {
      if ((s - h) % 2 != 0)
        return -1;
      if (s < h)
        result += (h-s)/2;
    }
    return result;
  }
};

// 204.66/250 pts