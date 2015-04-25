/* ========================================
 * Points :
 * Total : 250
 * Status :
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class TheNicePair {
public:
  int solve(vector <int> A) {
    vector<bool> ns(1001, true);
    FOR(d,2,501) {
      for (int i = 2*d; i <= 1000; i += d) {
        ns[i] = false;
      }
    }

    vector<int> primes;
    for (int i = 2; i < ns.size(); ++i) {
      if (ns[i]) {
        primes.emplace_back(i);
      }
    }
    int m = primes.size();
    int n = A.size();
    int k;

    vector<vector<int> > inits(m);
    int pi = 0;
    for (auto & p : primes) {
      int cnt = 0;
      REP(i,n) {
        if (A[i] % p == 0) {
          cnt++;
        }
        inits[pi].emplace_back(cnt);
      }
      pi++;
    }

    for (k = n-1; k >= 0; --k) {
      REP(i,n-k) {
        REP(pi,m) {
          if (inits[pi][i+k] - ( i ? inits[pi][i-1] : 0 ) >= (k+2)/2) {
            return k;
          }
        }
      }
    }

    return -1;
  }
};
