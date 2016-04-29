/* ========================================
 * Points : 331.91
 * Total : 500
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class NonDeterministicSubstring {
public:
  long long ways(string A, string B) {
    long long result = 0;
    unordered_set<string> dict;
    int n = A.size(), m = B.size();
    REP(i,n-m+1) {
      long long match = 1;
      REP(j,m) {
        if (B[j] != '?' && A[i+j] != B[j]) {
          match = 0;
          break;
        }
      }
      string As = A.substr(i,m);
      if (dict.find(As) == dict.end()) {
        result += match;
        dict.insert(As);
      }
    }

    return result;
  }
};
