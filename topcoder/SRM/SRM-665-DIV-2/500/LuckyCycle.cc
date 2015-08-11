/* ========================================
 * Points : 0
 * Total : 500
 * Status : WA
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class LuckyCycle {
public:
  int n, cur_dist, cur_fours;
  int** weighted_adjacency;
  vector<bool> visited;

  int dfs(int v) {
    visited[v] = true;

    if (cur_dist > 2 && cur_dist % 2 == 1 && abs(cur_fours - cur_dist / 2) <= 1) {
      return v;
    }

    FOR(u,1,n+1) {
      if (u == v || visited[u] || weighted_adjacency[u][v] == 0) {
        continue;
      }

      cur_dist++;
      if (weighted_adjacency[u][v] == 4) {
        cur_fours++;
      }
      int w = dfs(u);
      if (w != -1) {
        return w;
      }
      if (weighted_adjacency[u][v] == 4) {
        cur_fours--;
      }
      cur_dist--;
    }

    return -1;
  }

  pair<int, int> well_reachable(int v) {
    visited.assign(n+2, false);
    cur_dist = cur_fours = 0;
    int u = dfs(v);
    if (u == -1) {
      return make_pair(-1, -1);
    }
    if (cur_dist / 2 == cur_fours) {
      return make_pair(u, 4);
    }
    return make_pair(u, 7);
  }

  vector <int> getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight) {
    vector <int> result;
    n = edge1.size() + 1;

    weighted_adjacency = (int **) calloc(n+2, sizeof(int*));
    REP(i,n+3) {
      weighted_adjacency[i] = (int *) calloc(n+2, sizeof(int));
    }

    REP(i,n-1) {
      weighted_adjacency[edge1[i]][edge2[i]] = weight[i];
      weighted_adjacency[edge2[i]][edge1[i]] = weight[i];
    }

    // DFS
    REP(v,n) {
      MSG(v);
      pair<int, int> dest = well_reachable(v);
      MSG(dest.first);
      MSG(dest.second);

      if (dest.first != -1) {
        result.emplace_back(v);
        result.emplace_back(dest.first);
        result.emplace_back(dest.second);
        MSG("here");
        return result;
      }
    }

    REP(i,n+3) {
      free(weighted_adjacency[i]);
    }
    free(weighted_adjacency);

    return result;
  }
};
