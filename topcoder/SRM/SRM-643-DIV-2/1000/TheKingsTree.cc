/* ========================================
 * Points :
 * Total :
 * Status :
 ==========================================*/

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

// uncomment following line for debug mode
// #define DEBUG   

typedef pair<int,int> ii;

class TheKingsTree {
  int result;
  vector<int> par;
public:
  ii solve(int r) {
    int cost = 1;
    int other = 0;
    ii tmp;
    for (int i = 0; i < par.size(); ++i) {
      if (par[i] == r) {
        tmp = solve(i+1);
        cost += min(tmp.first, tmp.second);
        other += max(tmp.first, tmp.second);
      }
    }
    result += cost;
    return make_pair(cost, other);
  }

  int getNumber(vector <int> parent) {
    result = 0;
    par = parent;
    solve(0);

    return result;
  }
};
// not submitted
