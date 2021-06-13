 
/* ========================================

   ID: mathema6
   TASK: gen_max_test
   LANG: C++11

   * File Name : gen_max_test.cxx
   * Creation Date : 07-01-2021
   * Last Modified : Sun 13 Jun 2021 07:27:22 PM CEST
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
  int cases = 1;
  cout << cases << endl;

  // n, m...
  int n = 400000;
//   int n = 10;
  cout << n << endl;

  // 1st line
  FOR(i,1,n) {
    cout << i << " ";
  }
  cout << endl;

  // 1st line
  FOR(i,2,n) {
    cout << i << " ";
  }
  cout << 1 << " ";
  cout << endl;

  return 0;
}
