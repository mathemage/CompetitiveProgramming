/* ========================================
 * Points : 237.97
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class DecipherabilityEasy {
public:
  string check(string s, string t) {
    int n = s.size(), m = t.size();
    if (n != m+1) return "Impossible";

    REP (i,n) {
      string ss = s.substr(0,i) + s.substr(i+1);
      if (ss == t) return "Possible";
    }
    return "Impossible";
  }
};
