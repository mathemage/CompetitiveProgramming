 
/* ========================================

   ID: mathema6
   TASK: gen_max_test
   LANG: C++11

   * File Name : gen_max_test.cxx
   * Creation Date : 07-01-2021
   * Last Modified : Čt 7. ledna 2021, 23:59:22
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
  int cases = 1;
  cout << cases << endl;

  int lim = 300000;
  cout << lim << " " << lim << endl;

  REP(i,lim) {
    cout << lim << " ";
  }
  cout << endl;

  REP(i,lim) {
    cout << 1000000000 << " ";
  }
  cout << endl;

  return 0;
}
