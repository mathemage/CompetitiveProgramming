/* ========================================
 * Points : 150.14 (over 2 days)
 * Total : 500
 * Status : AC
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

    vector<pair<int, int>> intervals(n);
    REP(i,n) {
      intervals[i].first = l[i];
      intervals[i].second = r[i];
    }
    sort(ALL(intervals));

    vector<int> covers(n);
    REP(i,n) {
      for (auto & x : p) {
        covers[i] += intervals[i].first <= x && x <= intervals[i].second;
      }
    }

    vector<bool> interval_paired(n, false);
    for (auto & x : p) {
      /*
      MSG(x);
      cout << "covers[]:\t";
      REP(i,n) {
        cout << "[" << intervals[i].first
             << "," << intervals[i].second << "]:"
             << covers[i]
             << "\t";
      }
      cout << endl;  */
      // least occupied interval
      int idx = -1;
      REP(i,n) {
        if (!interval_paired[i]
            && intervals[i].first <= x && x <= intervals[i].second
            && (idx == -1 || (covers[i] < covers[idx])) ) {
          idx = i;
          //MSG(idx); MSG(intervals[i].first); MSG(intervals[i].second); cout << endl;
        }
      }

      if (idx == -1) {
        return "Impossible";
      }
      interval_paired[idx] = true;

      // update other intervals
      REP(i,n) {
        if (!interval_paired[i]
            && intervals[i].first <= x && x <= intervals[i].second) {
          covers[i]--;
        }
      }
    }

    return "Possible";
  }
};
