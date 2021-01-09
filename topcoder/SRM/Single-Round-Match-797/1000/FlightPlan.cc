/* ========================================
 * Points :
 * Total : 1000
 * Status : unsubmitted
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define ENDL "\n"
#define FO(I,A,B) for(int I = (A); I <= (B); ++I)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;


class FlightPlan {
public:
  long long fly(int R, int C, vector <int> H, int cup, int cdn, int clr) {
    vector<vector<long long>> min_costs(R, vector<long long>(C, LLONG_MAX));
    vector<vector<int>> max_heights(R, vector<i>(C, H[0]));
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    int n_visited = R * C;

    vector<int> dr = {0,0,1,-1};
    vector<int> dc = {1,-1,0,0};

    int cur_pos = 0;
    min_costs[0][0] = 0;
    long long new_cost;

    while (n_visited) {
      cur_r = cur_pos / C;
      cur_c = cur_pos % C;

      // visit neighbors
      REP(di,4) {
        r = cur_r + dr;
        c = cur_c + dc;
        if (0 <= r && r < R && 0 <= c && c < C && !visited[r][c]) {
          // relax neighbors
          pos = r * C + c;
          max_heights[r][c] = max(H[pos], max_heights[cur_r][cur_c]);
          new_cost = min_costs[cur_r][cur_c] + clr + (max_heights[r][c] - H[0]) * cup + (max_heights[r][c] - H[pos]) * cdn;
//           min_costs[r][c] = TODO
        }
      }

      cur_pos = get_closest_cell(min_costs);
    }

    return min_costs[R-1][C-1];
  }
};
