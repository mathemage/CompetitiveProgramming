/* ========================================
 * Points : 287.85, 185.88 (stod() version)
 * Total : 300
 * Status : AC, AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class CutoffRounder {
public:
  int round(string num, string cutoff) {
    return floor(stod(num)) + (stod(num) - floor(stod(num)) > stod(cutoff));
  }
};
