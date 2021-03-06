/* ========================================
 * Points :
 * Total :
 * Status : unsubmitted, AC in practice room
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

    const int SZ = 2001;
    bool vis[SZ][SZ];
    REP(i,SZ) REP(j,SZ) vis[i][j] = false;
    vis[1000][1000] = true;
    REP(i,x.size()) {
      vis[x[i]+1000][y[i]+1000] = true;
    }

    while (!q.empty()) {
      pair<int, int> pt = q.front();
      q.pop();
      result = max(result, pt.first);

      for (pair<int, int> d : vector<pair<int, int>> {{1,0}, {0,1}, {0,-1}, {-1,0}} ) {
        pair<int, int> npt = {pt.first + d.first, pt.second + d.second};
        if (!vis[npt.first+1000][npt.second+1000] && k > 0) {
          q.push(npt);
          vis[npt.first+1000][npt.second+1000] = true;
        }
      }

      if (pt == pair<int, int> {0,0} && --k)
        q.push({0,0});
    }

    return result;
  }
};
