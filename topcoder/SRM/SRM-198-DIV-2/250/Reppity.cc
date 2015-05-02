/* ========================================
 * Points : 192.72
 * Total : 250
 * Status : AC on #2
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Reppity {
public:
  int longestRep(string input) {
    int n = input.size();
    for (int l = n/2; l > 0; l--) {
      REP(a,n) FOR(b,a+l,n) {
        if (input.substr(a,l) == input.substr(b,l)) {
          return l;
        }
      }
    }
    return 0;
  }
};
