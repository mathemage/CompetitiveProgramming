/* ========================================
 * Points : 0
 * Total : 250
 * Status : WA AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class ChessFloor {
public:
  int minimumChanges(vector <string> floor) {
    int n = floor.size();
    int result = n*n;

    vector < vector<int> > cnt(2);
    cnt[0].assign(26,0);
    cnt[1].assign(26,0);
    REP(i,n) REP(j,n) {
      (cnt[(i + j) % 2][floor[i][j]-'a'])++;
    }

    REP(k,2) {
      REP(c,26) {
        MSG(cnt[k][c]);
      }
      cout << endl;
    }

    int w, b;
    int idx = 0;
    REP(k,2) {
      w = 0;
      REP(i,26) {
        if (cnt[idx][w] < cnt[idx][i]) {
          w = i;
        }
      }

      b = (w == 0) ? 1 : 0;
      REP(i,26) {
        if (i != w && cnt[1-idx][b] < cnt[1-idx][i]) {
          b = i;
        }
      }

      result = min(result, n*n - cnt[idx][w] - cnt[1-idx][b]);
      MSG(b); MSG(w);
      MSG(cnt[idx][w]); MSG(cnt[1-idx][b]);
      MSG(n*n - cnt[idx][w] - cnt[1-idx][b]);
      MSG(result);
      cout << endl;

      idx = 1 - idx;
    }

    return result;
  }
};
