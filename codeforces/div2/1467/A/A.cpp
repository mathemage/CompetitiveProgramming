 
/* ========================================
   * File Name : A.cpp
   * Creation Date : 08-01-2021
   * Last Modified : Pá 8. ledna 2021, 16:01:56
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1467/problem/0
   * Points :
   * Total : 500
   * Status : WA (pre #2) - WA (pre #2)
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

  if (n >= 2) {
    cout << 8;
  }

  if (n > 2) {
    n -= 2;
    int digit = 9;
    while (n--) {
      cout << digit;
      digit = (digit + 9) % 10;
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
