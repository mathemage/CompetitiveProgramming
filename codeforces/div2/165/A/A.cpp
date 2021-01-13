 
/* ========================================
   * File Name : A.cpp
   * Creation Date : 13-01-2021
   * Last Modified : St 13. ledna 2021, 18:45:44
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/problemset/problem/165/A
   * Points/Time : 26 m :-(
   * Total :
   * Status : AC
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FO(I,A,B) for(int I = (A); I <= (B); ++I)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;
// const int INF = INT_MAX;
const int INF = 2005;

void solve() {
  int n,x,y;
  cin >> n;
  vector<pair<int, int>> pt;
  vector<pair<int, int>> x_ends(2005, make_pair(INF, -INF));
  vector<pair<int, int>> y_ends(2005, make_pair(INF, -INF));
  REP(i,n) {
    cin >> x >> y;
    pt.push_back(make_pair(x,y));
    MSG(x); MSG(y);

    x_ends[x+1000].first  = min(x_ends[x+1000].first, y);
    x_ends[x+1000].second = max(x_ends[x+1000].second, y);
    MSG(x_ends[x+1000].first); MSG(x_ends[x+1000].second);

    y_ends[y+1000].first  = min(y_ends[y+1000].first, x);
    y_ends[y+1000].second = max(y_ends[y+1000].second, x);
    cerr << endl;
  }
  cerr << endl;

  long long result = 0LL;
  for (auto & xy : pt) {
    x = xy.first; y = xy.second;
    MSG(x); MSG(y);
    MSG(x_ends[x+1000].first); MSG(x_ends[x+1000].second);
    MSG(y_ends[y+1000].first); MSG(y_ends[y+1000].second);
    result += (x != y_ends[y+1000].first && x != y_ends[y+1000].second &&
               y != x_ends[x+1000].first && y != x_ends[x+1000].second);
    MSG(result);
    cerr << endl;
  }
  cout << result << endl;
}

int main() {
  int cases;
//   cin >> cases;
  cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
