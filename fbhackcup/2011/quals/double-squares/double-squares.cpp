/* ========================================

   ID: mathema6
   TASK: double-squares
   LANG: C++11
   (...for USACO solutions)

   * File Name : double-squares.cpp

   * Creation Date : 11-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : https://www.facebook.com/hackercup/problems.php?pid=112921602098268&round=4

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

int n,x,l,u,res;
int main() {
  cin >> n;
  REP(i,n) {
    cout << "Case #" << i+1 << ": ";
    cin >> x;
    res = l = 0; u = sqrt(x);
    while (l <= u) {
      if (l*l + u*u == x) {
        res++;
      }
      l++;
      u = sqrt(x-l*l);
    }
    cout << res << endl;
  }
  return 0;
}
