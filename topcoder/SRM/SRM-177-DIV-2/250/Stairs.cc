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

class Stairs {
public:
  int designs(int maxHeight, int minWidth, int totalHeight, int totalWidth) {
    int res = 0;
    int w = minWidth;
    while (w <= totalWidth) {
      int treads = totalWidth / w;
      if ((totalWidth % w == 0)
          && (totalHeight % (treads + 1) == 0)) {
          if (totalHeight / (treads + 1) <= maxHeight) {
            res++;
          } else {
            break;
          }
      }
      w++;
    }
    return res;
  }
};

// 130.20/250
