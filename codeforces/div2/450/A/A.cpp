 
/* ========================================
   * File Name : A.cpp
   * Creation Date : 07-01-2021
   * Last Modified : Čt 7. ledna 2021, 19:33:09
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/problemset/problem/450/A
   * Points :
   * Total :
   * Status : AC
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

void solve() {
  int n,m,ai;
  cin >> n >> m;

  long long result;
  int max_cycles = 0;
  REP(i,n) {
    cin >> ai;
    ai = (ai + m - 1) / m;
    if (ai >= max_cycles) {
      max_cycles = ai;
      result = i + 1;
    }
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
