 
/* ========================================
   * File Name : A_v2.cpp
   * Creation Date : 09-01-2021
   * Last Modified : So 9. ledna 2021, 23:30:28
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1467/problem/A
   * Points : 2m 10s
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
  int n;
  cin >> n;
  cout << 9;
  int digit = 8;
  while (--n) {
    cout << digit;
    digit++;
    digit%=10;
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
