/* ========================================
 * Points : 214.44
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

class DinkyFish {
public:
  int monthsUntilCrowded(int tankVolume, int maleNum, int femaleNum) {
    int result = 0;
    int a = min(maleNum, femaleNum);
    int b = max(maleNum, femaleNum);
    tankVolume *= 2;
    tankVolume -= b-a;
    MSG(a) MSG(b) MSG(tankVolume)

    while (2*a <= tankVolume) {
      result++;
      a *= 2;
    }

    return result;
  }
};
