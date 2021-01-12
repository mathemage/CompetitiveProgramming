 
/* ========================================
   * File Name : A.cpp
   * Creation Date : 12-01-2021
   * Last Modified : Út 12. ledna 2021, 19:06:19
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/problemset/problem/1004/A
   * Points/Time : 10m 30s
   * Total : 500
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

void solve() {
  int n,d;
  cin >> n >> d;
  vector<int> x(n);
  for (auto & xi : x) {
    cin >> xi;
  }

  unordered_set<int> positions;
  REP(i,n) {
    cerr << endl; MSG(i);
    for (auto & di : {-1,1}) {
      int pos = x[i] + di * d;

      bool far_enough = true;
      REP(j,n) {
        if (abs(x[j] - pos) < d) {
          far_enough = false;
          break;
        }
      }

      if (far_enough) {
        MSG(pos);
        positions.insert(pos);
      }
    }
  }
  cout << positions.size() << endl;
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
