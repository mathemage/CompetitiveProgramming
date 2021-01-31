/* ========================================
 * Points : 488.99 (39m 10s) - 339.25 (46m 40s)
 * Total : 1000
 * Status : WA (#7) - AC (!!!!)
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FO(I,A,B) for(int I = (A); I <= (B); ++I)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;
const long long INF = LLONG_MAX;

// direction vectors - 4 directions
const vector<int> DX4 = { 0, 0, -1, 1};
const vector<int> DY4 = {-1, 1,  0, 0};
const vector<pair<int,int>> DXY4 = { {0,-1}, {0,1}, {-1,0}, {1,0} };
// direction vectors - 8 directions
const vector<int> DX8 = {-1, -1, -1,   0, 0,   1,  1,  1};
const vector<int> DY8 = {-1,  0,  1,  -1, 1,  -1,  0,  1};
const vector<pair<int,int>> DXY8 = {
  {-1,-1}, {-1,0}, {-1,1},
  { 0,-1},         { 0,1},
  { 1,-1}, { 1,0}, { 1,1}
};


class FlightPlan {
public:
  vector<pair<int, int>> get_neighbors(int at_r, int at_c, int R, int C, vector<vector<bool>> & visited) {
    vector<pair<int, int>> result;
    REP(i,4) {
      int rr = at_r + DX4[i];
      int cc = at_c + DY4[i];
      if (0 <= min(rr,cc) && rr<R && cc<C && !visited[rr][cc]) {
        result.PB(MP(rr,cc));
      }
    }
    return result;
  }

  long long fly(int R, int C, vector<int> H, int cup, int cdn, int clr) {
    int start = 0;
    int end = R*C-1;
    long long result = INF;

    vector<vector<bool>> visited(R, vector<bool>(C));
    for (auto & H_lim : H) {
      if (H[start] > H_lim || H[end] > H_lim) {
        continue;
      }
//       MSG(H_lim);
      long long vcost = (long long)(H_lim-H[start])*cup + (long long)(H_lim-H[end])*cdn;

      REP(row,R) REP(col,C) {
        visited[row][col] = H[row * C + col] > H_lim;
      }
//       cerr << "visited:\n";
//       REP(row,R) {
//         REP(col,C) {
//           cerr << (visited[row][col] ? '#' : '.');
//         }
//         cerr << endl;
//       }

      // ---BFS---
      vector<vector<long long>> dist(R, vector<long long>(C, INF));
      queue<int> qr, qc;

      dist[0][0] = 0;
      qr.push(0), qc.push(0);

      while (!qc.empty()) {
        int r=qr.front(), c=qc.front();
        qr.pop(), qc.pop();
        visited[r][c] = true;

        if (r == R-1 && c == C-1) {
          break;
        }

        for (auto & neigh : get_neighbors(r, c, R, C, visited)) {
          if (!visited[neigh.F][neigh.S]) {
            dist[neigh.F][neigh.S] = dist[r][c]+1;
            qr.push(neigh.F); qc.push(neigh.S);
            visited[neigh.F][neigh.S] = true;
          }
        }
      }
      // ---------

      if (dist[R-1][C-1] != INF) {
        long long hcost = dist[R-1][C-1]*clr;
        MINUPDATE(result, hcost + vcost);
//         MSG(dist[R-1][C-1]) MSG(hcost) MSG(vcost) MSG(result);
      }
    }

    return result;
  }
};
