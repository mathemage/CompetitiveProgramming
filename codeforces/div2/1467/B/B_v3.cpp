 
/* ========================================
   * File Name : B_v3.cpp
   * Creation Date : 17-01-2021
   * Last Modified : Ne 17. ledna 2021, 01:20:14
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1467/problem/B
   * Points/Time : 15m 20s - 45m
   * Total :
   * Status : WA #3 - AC
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

int sign(int x) {
  return x ? (x>0?1:-1) : 0;
}

bool is_extreme(int l, int m, int r) {
  return sign(l-m) * sign(r-m) > 0;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<bool> extremes(n);
  REP(i,n) {
    cin >> a[i];
  }

  FO(j,1,n-2) {
    extremes[j] = is_extreme(a[j-1], a[j], a[j+1]);
//     MSG(extremes[j]);
  }

  int max_delta = 0;
  FO(j,1,n-2) {
    for (auto new_val: {a[j-1], a[j+1]}) {
      int delta = extremes[j-1] + extremes[j] + extremes[j+1];
//       cerr << endl; MSG(j); MSG(delta);
      swap(a[j], new_val);
//       if (j == 4) {
//         MSG(a[j]); MSG(new_val);
//       }

      for (auto & dj: {-1, 0, 1}) {
        int jj = j+dj;
//         if (j==4) { MSG(jj); MSG(a[jj]);}
        if (0<jj && jj<n-1) {
          delta -= is_extreme(a[jj-1], a[jj], a[jj+1]);
//           if (j==4) { MSG(delta); }
        }
      }
      MAXUPDATE(max_delta, delta);
      swap(a[j], new_val);

//       if (j == 4) {
//         MSG(delta);
//       }
    }
  }

//   MSG(accumulate(ALL(extremes), 0)); MSG(max_delta);
  long long result = accumulate(ALL(extremes), 0) - max_delta;
  cout << result << endl;
//   cerr << endl;
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
