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


class TrianglesContainOriginEasy {
public:
  int getHalfPlane(int ax, int ay, int bx, int by) {
    return (-bx) * (ay - by) - (ax - bx) * (-by); 
  }

  bool validTriangle(int ax, int ay, int bx, int by, int cx, int cy) {
    bool b1 = getHalfPlane(ax, ay, bx, by) < 0;
    bool b2 = getHalfPlane(bx, by, cx, cy) < 0;
    bool b3 = getHalfPlane(cx, cy, ax, ay) < 0;

    return ((b1 == b2) && (b2 == b3));
  }

  int count(vector <int> x, vector <int> y) {
    int res = 0;
    int N = x.size();

    REP(i,N) {
      FOR(j,i+1,N) {
        FOR(k,j+1,N) {
          res += validTriangle(x[i], y[i], x[j], y[j], x[k], y[k]);
        }
      }
    }
    return res;
  }
};
