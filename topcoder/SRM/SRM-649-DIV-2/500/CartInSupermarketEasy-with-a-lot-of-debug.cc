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
    REP(j,K+1) dp[1][j] = 1;
    REP(i,N+1) dp[i][0] = i;

    FOR(i,2,N+1) FOR(j,1,K+1) {
      dp[i][j] = 1+dp[i-1][j];
      //cout << endl;
      //MSG(j) MSG(i/2+1)
      REP(a,j) FOR(x,2,i/2+1) {
        dp[i][j] = min(dp[i][j], 1+max(dp[x][a], dp[i-x][j-1-a]));
        //if (i == N && j==K) {
        //  MSG(a) MSG(x)
        //}
      }
    }

    /*
    cerr << "i\\j\t";
    REP(j,K+1) cerr << j << '\t';
    cerr << endl;
    REP(i,N+1) {
      cerr << i << "\t";
      REP(j,K+1) cerr << dp[i][j] << "\t";
      cerr << endl;
    }
    vector<vector<int> > xs(N+1, vector<int> (K+1,-1));
    vector<vector<int> > ys(N+1, vector<int> (K+1,-1));
    FOR(i,2,N+1) FOR(j,1,K+1) {
      if (dp[i][j] == 1+dp[i-1][j]) {
        xs[i][j] = i-1;
        ys[i][j] = j;
      }
      REP(a,j) FOR(x,2,(i+1)/2) {
        if (dp[i][j] == 1+dp[x][a]) {
          xs[i][j] = x;
          ys[i][j] = a;
        } else if (dp[i][j] == 1+dp[i-x][j-1-a]) {
          xs[i][j] = i-x;
          ys[i][j] = j-1-a;
        }
      }
    }
    cerr << "\ni\\j\t";
    REP(j,K+1) cerr << j << '\t';
    cerr << endl;
    REP(i,N+1) {
      cerr << i << "\t";
      REP(j,K+1) {
        cerr << xs[i][j] << ",";
        cerr << ys[i][j] << "\t";
      }
      cerr << endl;
    }
    */

    int res = dp[N][K];
    REP(j,K) res = min(res, dp[N][j]);
    return res;
  }
};
