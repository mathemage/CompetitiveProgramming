/* ========================================

   ID: mathema6
   TASK: D
   LANG: C++11
   (...for USACO solutions)

   * File Name : D.cpp

   * Creation Date : 18-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/500/problem/D

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

#define ERR(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c))
    v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
  err(++it, args...);
}

long n,q;
struct edge {
  long v1, v2, l;
};
vector<vector<long>> neighs;
vector<edge> e;
vector<long> sizes;
vector<bool> visited;
vector<long> parent;

// also pre-compute "sizes"
long dfs(long r) {
  visited[r] = true;
  for (long v : neighs[r]) {
    if (!visited[v]) {
      parent[v] = r;
      sizes[r] += dfs(v);
    }
  }
  return sizes[r];
}

int main() {
  cin >> n;
  neighs.resize(n);
  sizes.assign(n, 1);
  e.resize(n-1);
  visited.assign(n, false);
  parent.assign(n, -1);

  // init graph
  REP(i,n-1) {
    cin >> e[i].v1 >> e[i].v2 >> e[i].l;
    e[i].v1--;
    e[i].v2--;
    neighs[e[i].v1].emplace_back(e[i].v2);
    neighs[e[i].v2].emplace_back(e[i].v1);
  }
  dfs(0);
  visited.clear();
  neighs.clear();

  // initial sum
  double ans = 0; 
  for (auto & x : e) {
    long a = x.v1, b = x.v2;
    if (parent[a] == b) swap(a,b);
    ans += 6.0 * x.l * sizes[b] / n * (n-sizes[b]) / (n-1);
  }

  // queries
  long index, change;
  cin >> q;
  REP(i,q) {
    cin >> index >> change;
    index--;
    long a = e[index].v1, b = e[index].v2;
    if (parent[a] == b) swap(a,b);
    ans -= 6.0 * (e[index].l-change) * sizes[b] / n * (n-sizes[b]) / (n-1);
    e[index].l = change;
    cout << fixed << setprecision(10) << ans << endl;
  }

  return 0;
}
