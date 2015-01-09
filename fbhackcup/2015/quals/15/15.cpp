/* ========================================

   ID: mathema6
   TASK: 15
   LANG: C++11
   (...for USACO solutions)

   * File Name : 15.cpp

   * Creation Date : 09-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL :

   * Points Gained (in case of online contest) :

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

int main() {
  int t, ma, mi;
  cin >> t;

  string num;
  REP(i,t) {
    printf("Case #%d: ", i+1);
    cin >> num;
    ma = mi = 0;
    for (int i = 1; i <  num.size(); ++i) {
      if (num[i] <= num[mi] && num[i] != '0') {
        mi = i;
      }
      if (num[i] >= num[ma]) {
        ma = i;
      }
    }

    swap(num[0], num[mi]);
    cout << num << " ";
    swap(num[0], num[mi]);
    swap(num[0], num[ma]);
    cout << num << endl;
  }
  return 0;
}
