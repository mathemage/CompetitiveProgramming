/* ========================================
 * Points : 75
 * Total : 250
 * Status : WA - WA - AC
 ==========================================*/
// WA: 546 -> 500 (got 543)
// WA: 992 -> 930 (got 989)

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cerr << #a << " == " << a << endl;


class PlusCastle {
public:
  int maximiseClosedFigures(int k) {
    int side = sqrt(k);
    int result = pow(side - 1, 2);
    MSG(side); MSG(pow(side - 1, 2));

    MSG(k); MSG(result);
    k -= pow(side, 2);
    MSG(k);
    result += max(0, k - (k > side ? 2 : 1));
    MSG(result);

    return result;
  }
};
