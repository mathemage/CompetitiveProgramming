/* ========================================
 * Points : 92.97
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class StringMult {
public:
  string times(string sFactor, int iFactor) {
    string result = "";

    if (iFactor < 0) {
      reverse(ALL(sFactor));
      iFactor *= -1;
    }

    REP(i,iFactor) {
      result += sFactor;
    }
    return result;
  }
};