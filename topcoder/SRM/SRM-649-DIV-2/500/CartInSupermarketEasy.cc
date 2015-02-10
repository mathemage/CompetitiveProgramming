/* ========================================
 * Status : unsubmitted, passed systests
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class CartInSupermarketEasy {
public:
  int calc(int N, int K) {
    vector<vector<int> > dp(N+1, vector<int> (K+1, 0));
    REP(j,K+1) dp[1][j] = 1;
    REP(i,N+1) dp[i][0] = i;

    FOR(i,2,N+1) FOR(j,1,K+1) {
      dp[i][j] = 1+dp[i-1][j];
      REP(a,j) FOR(x,2,i/2+1) {
        dp[i][j] = min(dp[i][j], 1+max(dp[x][a], dp[i-x][j-1-a]));
      }
    }

    int res = dp[N][K];
    REP(j,K) res = min(res, dp[N][j]);
    return res;
  }
};
