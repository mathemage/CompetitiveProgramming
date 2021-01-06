 
/* ========================================
   * File Name : A.cpp
   * Creation Date : 06-01-2021
   * Last Modified : St 6. ledna 2021, 18:39:20
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/problemset/problem/272/A
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
  int n,f;
  int others = 0;
  cin >> n;
  int mod = n+1;
  while (n--) {
    cin >> f;
    others += f;
    others %= mod;
  }

  long long result = 0LL;
  REP(dima,5) {
    if ((others+dima)%mod) {
      result++;
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
