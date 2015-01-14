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
#define MSG(a) cout << #a << " == " << (a) << endl;

const int CLEAN = -1;
int main() {
  int t, n, d, d2, b, e;
  cin >> t;

  string num;
  REP(j,t) {
    printf("Case #%d: ", j+1);
    cin >> num;
    n = num.size();
    vector<int> mins(n);
    vector<int> maxs(n);
    n--;
    mins[n] = maxs[n] = n;
    while (--n>=0) {
      if (num[n] >= num[mins[n+1]]) {
        mins[n] = mins[n+1];
      } else {
        mins[n] = n;
      }

      if (num[n] <= num[maxs[n+1]]) {
        maxs[n] = maxs[n+1];
      } else {
        maxs[n] = n;
      }
    }


    mins[0] = 0;
    for (int i = num.size()-1; i >= 0; --i) {
      if (num[i] != '0' && num[i] < num[mins[0]])
        mins[0] = i;
    }

    /*
    MSG(num)
    cout << "mins: ";
    REP(i,num.size()) {
      cout << mins[i] << " ";
    }
    cout << endl;
    cout << "maxs: ";
    REP(i,num.size()) {
      cout << maxs[i] << " ";
    }
    cout << endl;
  */
    REP(i,num.size()) {
      if ((mins[i] > i && num[mins[i]] < num[i])
          || i == num.size()-1) {
        swap(num[i], num[mins[i]]);
        cout << num << " ";
        swap(num[i], num[mins[i]]);
        break;
      }
    }
    REP(i,num.size()) {
      if ((maxs[i] > i && num[maxs[i]] > num[i])
          || i == num.size()-1) {
        swap(num[i], num[maxs[i]]);
        cout << num << endl;
        swap(num[i], num[maxs[i]]);
        break;
      }
    }
  }
  return 0;
}
