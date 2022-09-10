 
/* ========================================

   ID: mathema6
   TASK: gen_max_test
   LANG: C++11

   * File Name : gen_max_test.cxx
   * Creation Date : 07-01-2021
   * Last Modified : Sun 11 Sep 2022 05:08:47 PM CEST
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL :
   * Points :
   * Total :
   * Status :
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(I,A,B) for(int I = (A); I <= (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N-1)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

void solve() {
  long long result = 0LL;
  cout << result << endl;
}

using ll = long long;

int main() {
  // t
  int cases = 55;
  cout << cases << endl;

  REP(tt,cases) {
    // n, m...
    int N = 500000;
    int Q = 500000;

    cout << N << endl;
    REP(_,N) {
      cout << "0 0" << endl;
    }
    cout << endl;

    cout << Q << endl;
    REP(j,Q) {
      ll coord=1000000000-j;
      cout << coord << " " << coord << endl;
    }
    cout << endl;
  }
  return 0;
}
