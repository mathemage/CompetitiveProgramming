 
/* ========================================
   * File Name : A_v2.cpp
   * Creation Date : 16-01-2021
   * Last Modified : So 16. ledna 2021, 00:14:22
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/problemset/problem/165/A
   * Points/Time :
   * Total :
   * Status :
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
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

void solve() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  REP(i,n) {
    cin >> x[i] >> y[i];
  }

  vector<vector<bool>> neigh(n, vector<bool>(4));
  REP(i,n) {
    REP(j,n) {
      if (x[i] == x[j]) {
        if (y[i] > y[j]) { neigh[i][0] = true; }
        if (y[i] < y[j]) { neigh[i][1] = true; }
      }
      if (y[i] == y[j]) {
        if (x[i] > x[j]) { neigh[i][2] = true; }
        if (x[i] < x[j]) { neigh[i][3] = true; }
      }
    }
  }

  long long result = 0LL;
  for (auto & ni: neigh) {
    result += accumulate(ALL(ni), 0) == 4;
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
