 
/* ========================================
   * File Name : A.cpp
   * Creation Date : 19-01-2021
   * Last Modified : Út 19. ledna 2021, 23:36:29
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : http://codeforces.com/contest/1474/problem/A
   * Points/Time : 12m 30s
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
  string b;
  cin >> b;

  int prev = CLEAN;
  for (auto & digit: b) {
    for (auto & val: {1,0}) {
      int new_val = (digit-'0') + val;
      if (new_val != prev) {
        cout << val;
        prev = new_val;
        break;
      }
    }
  }
  cout << endl;
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
