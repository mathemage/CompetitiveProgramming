/* ========================================
 * Points : 150.14 (over 2 days) 150.00 (re-submission)
 * Total : 500
 * Status : AC AC (faster)
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class SegmentsAndPoints {
public:
  string isPossible(vector <int> p, vector <int> l, vector <int> r) {
    int n = p.size();
    sort(ALL(p));

    vector<bool> interval_paired(n, false);
    for (auto & x : p) {
      int idx = -1;
      REP(i,n) {
        if (!interval_paired[i]
            && l[i] <= x && x <= r[i]
            && (idx == -1 || (r[i] < r[idx])) ) {
          idx = i;
        }
      }

      if (idx == -1) {
        return "Impossible";
      }
      interval_paired[idx] = true;
    }

    return "Possible";
  }
};
