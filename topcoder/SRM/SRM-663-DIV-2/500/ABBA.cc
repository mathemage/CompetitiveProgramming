/* ========================================
 * Points : 381.03
 * Total : 500
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class ABBA {
public:
  string canObtain(string initial, string target) {
    int len = target.size();

    while (len > initial.size()) {
      if (target[len-1] == 'B') {
        reverse(target.begin(), target.begin() + len-1);
      }
      len--;
    }

    return (initial == target.substr(0, initial.size())) ? "Possible" : "Impossible";
  }
};
