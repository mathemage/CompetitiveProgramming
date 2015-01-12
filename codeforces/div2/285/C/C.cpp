/* ========================================

   ID: mathema6
   TASK: C
   LANG: C++11
   (...for USACO solutions)

   * File Name : C.cpp

   * Creation Date : 12-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/501/problem/C

   * Points Gained (in case of online contest) : 1242 / 1500

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

int n;
int main() {
  cin >> n;
  vector<int> d(n);
  vector<int> s(n);
  queue<int> q;

  REP(i,n) {
    cin >> d[i] >> s[i];
    if (d[i] == 1)
      q.push(i);
  }

  vector<pair<int, int>> edges;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (d[u] != 1)
      continue;

    int v = s[u];
    edges.push_back({u, v});
    s[v] ^= u;
    if (--d[v] == 1)
      q.push(v);
  }
  
  cout << edges.size() << endl;
  for (int i = 0; i < edges.size(); ++i) {
    cout << edges[i].first << " " << edges[i].second << endl;
  }
  return 0;
}
