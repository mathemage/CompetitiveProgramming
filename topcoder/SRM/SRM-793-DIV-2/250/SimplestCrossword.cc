/* ========================================
 * Points : 190.40
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

const int CLEAN = -1;

class SimplestCrossword {
public:
  vector <string> construct(string H, string V) {

    int n_h = H.size();
    int n_v = V.size();

    vector <string> result(n_v);
    int R = CLEAN, C = CLEAN;
//     MSG(result[R]) MSG(H);
    REP(r,n_v) {
      result[r].resize(n_h);
      REP(c,n_h) {
        result[r][c] = '.';
        if (V[r] == H[c]) {
          R = r;
          C = c;
        }
      }
    }

    if (R == CLEAN) {
      return {};
    }

//     MSG(result[R]) MSG(H);
    result[R] = H;
    REP(r,n_v) {
//       MSG(result[r]);
      result[r][C] = V[r];
    }
    return result;
  }
};
