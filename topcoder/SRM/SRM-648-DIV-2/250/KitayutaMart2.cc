/* ========================================
 * Points : 244.31
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class KitayutaMart2 {
public:
  int numBought(int K, int T) {
    int result = 1;
    T /= K;
    int pow = 1;
    while (T > 1) {
      result++;
      pow *= 2;
      T -= pow;
    }

    return result;
  }
};
