/* ========================================
 * Points : 104.36
 * Total : 255
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class XorBoardDivTwo {
public:
  int theMax(vector <string> board) {
    int result = 0, m = board.size(), n = board[0].size();

    char c;
    REP(i,m) REP(j,n) {
      int t = 0;
      REP(k,m) REP(l,n) {
        if (i == k && l == j) c = '1';
        else if (i == k || l == j) c = '0';
        else c = '1';

        t += board[k][l] == c;
      }
      result = max(result, t);
    }

    return result;
  }
};
