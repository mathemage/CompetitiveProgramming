 
/* ========================================

   ID: mathema6
   TASK: gen_max_test
   LANG: C++11

   * File Name : gen_max_test.cxx
   * Creation Date : 07-01-2021
   * Last Modified : Thu 10 Jun 2021 07:31:20 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points :
   * Total :
   * Status :
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
  long long result = 0LL;
  cout << result << endl;
}

int main() {
  // t
  int n = 1e5;
  int cases = 2e5/n;
  cout << cases << endl;

  REP(tt,cases) {
    // n, m...
//     int l = 1, r = 1e9;
    int l = 1;
    int r = 1e9;
    cout << n << " " << l << " " << r << endl;
    REP(i,n) {
      cout << i+1 << " ";
    }
    cout << endl;
  }

  return 0;
}
