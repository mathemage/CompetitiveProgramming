/* ========================================
 * Points : 0
 * Total : 250
 * Status : failed systests, now working
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

class TheKingsArmyDiv2 {
public:
  int getNumber(vector <string> state) {
    int r, c;
    r = state.size();
    c = state[0].size();
    bool oneHappy = false;
    REP(i,r) {
      REP(j,c) {
        if (state[i][j] == 'H') {
          oneHappy = true;
          if (j+1<c && state[i][j+1] == 'H') {
            return 0;
          }
          if (i+1<r && state[i+1][j] == 'H') {
            return 0;
          }
        }
      }
    }

    return oneHappy ? 1 : 2;
  }
};
