/* ========================================
 * Points :
 * Total :
 * Status : unsubmitted
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
    REP(j,K+1) dp[0][j] = 0;
    REP(j,K+1) dp[1][j] = 1;
    REP(i,N+1) dp[i][0] = i;

    FOR(i,2,N+1) FOR(j,1,K+1) {
      dp[i][j] = 1+dp[i-1][j];
      int x = i/2, y = i-x;
      REP(a,j) {
        dp[i][j] = min(dp[i][j], 1+min(dp[x][a], dp[y][max(0,j-1-a)]));
      }
    }

    REP(i,N+1) {
      REP(j,K+1) cout << dp[i][j] << "\t";
      cout << endl;
    }
    return dp[N][K];
  }
};
