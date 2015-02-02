/* ========================================
 * Points : 247.74
 * Total : 500
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Fragile2 {
  int n;
public:
  int bfs(vector<string> gr) {
    int res = 0;
    queue<int> q;
    vector<bool> vis(n, false);
    vector<bool> fin(n, false);

    REP(v,n) {
      if (!fin[v]) {
        res++;
        q.push(v);
        while (q.size()) {
          int u = q.front(); q.pop();
          if (!fin[u]) {
            vis[u] = true;
            REP(i,n) {
              if (!vis[i] && gr[min(i,u)][max(i,u)] == 'Y') {
                vis[i] = true;
                q.push(i);
              }
            }
            fin[u] = true;
          }
        }
      }
    }

    return res;
  }

  int countPairs(vector <string> graph) {
    int result = 0;
    n = graph.size();
    vector<string> gr;
    int comps = bfs(graph);

    REP(i,n) FOR(j,i+1,n) {
      gr = graph;
      REP(k,n) {
        gr[i][k] = 'N';
        gr[j][k] = 'N';
        gr[k][i] = 'N';
        gr[k][j] = 'N';
      }
      if (comps < bfs(gr) - 2) {
        result++;
      }
    }

    return result;
  }
};
