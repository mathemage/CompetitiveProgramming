/* ========================================
 * Points :
 * Total :
 * Status : unsubmitted (see Xanthic's solution)
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
    int vis[2005][2005];
    REP(i,2005) REP(j,2005) {
      vis[i][j] = -1;
    }
    queue<pair<int, int>> q;
    q.push({0,0});
    vis[1000][1000] = 0;

    set<pair<int, int>> xy;
    REP(i,x.size()) {
      xy.insert({x[i],y[i]});
    }

    while (!q.empty()) {
      pair<int, int> pt = q.front();
      q.pop();
      if (pt.first > result)
        result = pt.first;

      for (pair<int, int> d : vector<pair<int, int>> {{1,0}, {0,1}, {0,-1}, {-1,0}} ) {
        pair<int, int> npt = {pt.first + d.first, pt.second + d.second};
        if (npt.first < -50 || npt.second < -50 || 
            vis[npt.first+1000][1000+npt.second] != -1 ||
            vis[pt.first+1000][1000+pt.second] >= k)
          continue;

        if (xy.find( {npt.first, npt.second} ) == xy.end()) {
          q.push(npt);
          vis[npt.first+1000][1000+npt.second] = vis[pt.first+1000][1000+pt.second] + 1;
        }
      }
    }

    return result;
  }
};
