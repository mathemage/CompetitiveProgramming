/* ========================================
 * Points : 230.51
 * Total : 250
 * Status : 1st attempt
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

class OnLineRank {
public:
  int calcRanks(int k, vector <int> scores) {
    int result = scores.size();
    for (int i = 0; i < scores.size(); ++i) {
      for (int j = max(i-k,0); j < i; ++j) {
        result += (scores[j] > scores[i]);
      }
    }

    return result;
  }
};
