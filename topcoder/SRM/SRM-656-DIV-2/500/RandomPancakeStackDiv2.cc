/* ========================================
 * Points : 242.63
 * Total : 500
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class RandomPancakeStackDiv2 {
public:
  vector<bool> used;
  vector<int> d;
  int n;

  double dfs(int head, int arity, int ac) {
    if (arity == 0) {
      return ac;
    }

    used[head] = true;
    double result = 0;

    REP(i,n) {
      if (!used[i]) {
        if (i > head) {
          result += ac;
        } else {
          result += dfs(i, arity-1, ac + d[i]);
        }
      }
    }
    used[head] = false;
    return result / arity;
  }

  double expectedDeliciousness(vector <int> del) {
    d = del;
    n = d.size();
    used.assign(n, false);

    double result = 0;
    REP(i,n) {
      result += dfs(i,n-1,d[i]);
    }

    return result / n;
  }
};
