/* ========================================

   ID: mathema6
   TASK: studious-student
   LANG: C++11
   (...for USACO solutions)

   * File Name : studious-student.cpp

   * Creation Date : 11-01-2015

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

int n, m;
bool cmp(string l, string u) {
  for (int i = 0; i < max(l.size(), u.size()); ++i) {
    if ( l[i % l.size()] < u[i % u.size()] ) {
      return true;
    }
    if ( l[i % l.size()] > u[i % u.size()] ) {
      return false;
    }
  }
  return false;
}

int main() {
  cin >> n;
  REP(i,n) {
    printf("Case #%d: ", i+1);
    cin >> m;
    vector<string> words(m);
    REP(j,m) {
      cin >> words[j];
    }
    sort(ALL(words), cmp);
    for (string w : words)
      cout << w;
    cout << endl;
  }
  return 0;
}
