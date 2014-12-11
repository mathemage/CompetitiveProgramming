// 89.22 pts
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


class DifferentStrings {
public:
  int minimize(string A, string B) {
    int res = 51;

    FOR(s,0,B.size() - A.size() + 1) {
      int dist = 0;
      REP(i,A.size()) {
        dist += A[i] != B[s+i];
      }
      res = min(dist, res);
    }
    return res;
  }
};
