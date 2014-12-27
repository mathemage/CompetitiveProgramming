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

class TheKingsTree {
  int result;
  vector<int> par;
public:
  pair<int,int> solve(int r) { // returns optimal counts of colors
    int cost = 1;
    int under = 0;
    pair<int,int> tmp;
    for (int i = 0; i < par.size(); ++i) {
      if (par[i] == r) {
        MSG(i) MSG(par[i])
        tmp = solve(i+1);
        cost += min(tmp.first(), tmp.second());
        under += tmp.first() + tmp.second();
        MSG(cost)
      }
    }
    result += cost;
    return cost;
  }

  int getNumber(vector <int> parent) {
    result = 0;
    par = parent;
    int last = solve(0);

    return result + last;
  }
};
// not submitted
