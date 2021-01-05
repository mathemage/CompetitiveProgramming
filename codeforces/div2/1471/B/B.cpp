 
/* ========================================
   * File Name : B.cpp
   * Creation Date : 05-01-2021
   * Last Modified : Út 5. ledna 2021, 20:27:52
   * Created By : Karel Ha <mathemage@gmail.com>
   * URL : https://codeforces.com/contest/1471/problem/B
   * Points : 478
   * Total : 750
   * Status : WA (#5) - AC (5 pretests)
   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << (a) << endl;

const int CLEAN = -1;
const int UNDEF = -42;

int main() {
  int t,n,x;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    vector<int> a(n);
    vector<int> exp(n,0);
    REP(i,n) {
      cin >> a[i];
      int ai = a[i];
      while (ai % x == 0) {
        exp[i]++;
        ai /= x;
      }
    }

    long long mi = *min_element(ALL(exp));
    long long result = (1LL + mi) * accumulate(ALL(a), 0LL);

    REP(i,n) {
      if (exp[i] > mi) {
        result += a[i];
      } else {
        break;
      }
    }

    cout << result << endl;
  }
  return 0;
}
