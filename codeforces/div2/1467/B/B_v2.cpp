 
/* ========================================
   * File Name : B_v2.cpp
   * Creation Date : 08-01-2021
   * Last Modified : So 9. ledna 2021, 00:56:37
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1467/problem/B
   * Points :
   * Total : 1000
   *
   * Status : WA (#2 'signed integer overflow' on the line 30)
   * - WA (#2 'signed integer overflow' on the line 30)
   * - WA (#2)
   * - AC (!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
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

int is_extreme(int l, int m, int r) {
//   return int((m-l)*(m-r) > 0);
  l -= m;
  r -= m;
  return int( (l > 0 && r > 0) || (l < 0 && r < 0) );
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto & ai : a) {
    cin >> ai;
  }

  long long result = 0LL;
  vector<int> extremes(n,0);
  FO(j,1,n-2) {
    extremes[j] = is_extreme(a[j-1], a[j], a[j+1]);
    result += extremes[j];
  }
//   cerr << "extremes: ";
//   for (auto & ex : extremes) {
//     cerr << ex;
//   }
//   cerr << endl;

  int max_delta = 0;
  FO(j,1,n-2) {
    if (extremes[j]) {
      int delta = extremes[j-1] + extremes[j] + extremes[j+1];

      if (extremes[j-1] != extremes[j+1]) {
        for (auto & dj : {-1,1}) {
          int next_j = j+2*dj;
          if (!extremes[j+dj] && (0 <= next_j && next_j < n)) {
//             MSG(j); MSG(dj); MSG(delta);
//             MSG(j-dj) MSG(j+dj) MSG(next_j);
//             MSG(a[j-dj]) MSG(a[j+dj]) MSG(a[next_j]);
//             MSG(is_extreme(a[j-dj], a[j+dj], a[next_j]));
            delta -= is_extreme(a[j-dj], a[j+dj], a[next_j]);
//             MSG(delta);
          }
        }
      }
      max_delta = max(max_delta, delta);
    }
  }

  cout << result - max_delta << endl;
}

int main() {
  int cases;
  cin >> cases;
//   cases = 1;
  while (cases--) {
    solve();
  }
  return 0;
}
