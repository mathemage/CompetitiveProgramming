/* ========================================

   * File Name : ae00.cpp

   * Creation Date : 03-01-2016

   * Last Modified : Sun 03 Jan 2016 10:49:14 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/AE00/

   * Status : AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

#define REP(I,N)   FOR(I,0,N)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(A)     (A).begin(), (A).end()

int main() {
  int n, res = 0;
  cin >> n;
  for (int a = 1; a <= n; a++) {
    res += min(n / a, a);
  }
  cout << res << endl;
  return 0;
}
