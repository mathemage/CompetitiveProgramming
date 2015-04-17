/* ========================================
 * Points : 243.67
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class CorruptedMessage {
public:
  string reconstructMessage(string s, int k) {
    vector<int> cn(26);
    for (auto & x : s) {
      cn[x-'a']++;
    }
    REP(i,26) {
      if (cn[i] + k == s.size()) {
        string result;
        REP(j,s.size()) {
          result += (i+'a');
        }
        return result;
      }
    }
  }
};
