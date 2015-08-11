/* ========================================
 * Points : 206.64
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class LuckyXor {
public:
  int construct(int a) {
    FOR(b,a+1,101) {
      int c = a ^ b;
      if (1 <= c && c <= 100) {
        bool lucky = true;
        for (auto & x : to_string(c)) {
          if (x != '4' && x != '7') {
            lucky = false;
            break;
          }
        }

        if (lucky) {
          return b;
        }
      }
    }
    return -1;
  }
};
