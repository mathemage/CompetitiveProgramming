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


class TheGridDivTwo {
public:
  int find(vector <int> x, vector <int> y, int k) {
    int result = 0;
    queue<pair<int, int>> q;
    q.push({0,0});
    vector<bool> vis(1050 * 1050, false);
    int cnt = 1;

    while (!q.empty() && k >= 0) {
      pair<int, int> pt = q.front();
      q.pop();
      if (pt.first > result)
        result = pt.first;
      vis[(pt.first+50)*1050 +pt.second] = true;

      for (pair<int, int> d : vector<pair<int, int>> {{1,0}, {0,1}, {0,-1}, {-1,0}} ) {
        pair<int, int> npt = {pt.first + d.first, pt.second + d.second};
        if (npt.first < -50 || npt.second < -50 || 
            vis[(npt.first+50)*1050 + npt.second])
          continue;

        bool ok = true;
        REP(i,x.size()) {
          if (npt.first == x[i] && npt.second == y[i]) {
            ok = false;
            break;
          }
        }
        if (ok) q.push(npt);

        if (d.second == 0) break;
        if (d.second == -1) break;
      }

      if (pt.first == 0 && pt.second == 0) {
        k--;
        q.push({0,0});
      }
      ++cnt;
      MSG(k) MSG(pt.first) MSG(pt.second) cout << endl;
    }
    MSG(cnt)

    return result;
  }
};
