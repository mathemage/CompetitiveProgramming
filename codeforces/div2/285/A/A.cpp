/* ========================================

   ID: mathema6
   TASK: A
   LANG: C++11
   (...for USACO solutions)

   * File Name : A.cpp

   * Creation Date : 12-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/501/problem/A

   * Points Gained (in case of online contest) : 492 / 500

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

int a, b,c,d;
int main() {
  cin >> a >> b >> c >> d;
  int m = max(3*a/10, a - a * c / 250);
  int v = max(3*b/10, b - b * d / 250);
  if (m == v) cout << "Tie";
  if (m < v) cout << "Vasya";
  if (m > v) cout << "Misha";
  return 0;
}
