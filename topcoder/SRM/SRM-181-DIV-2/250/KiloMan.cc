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

// uncomment following line for debug mode
#define DEBUG

#ifdef DEBUG
#define MSG(a) cout << #a << " == " << a << endl;
#else
#define MSG(a) ;
#endif

class KiloMan {
public:
  int hitsTaken(vector <int> pattern, string jumps) {
    int result = 0;
    for (int i = 0; i < jumps.size(); ++i) {
      if (jumps[i] == 'S' && pattern[i] < 3) result++;
      if (jumps[i] == 'J' && pattern[i] > 2) result++;
    }
    return result;
  }
};
