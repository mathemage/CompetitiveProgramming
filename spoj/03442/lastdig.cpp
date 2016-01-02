/* ========================================

   * File Name : lastdig.cpp

   * Creation Date : 02-01-2016

   * Last Modified : Sat 02 Jan 2016 11:59:04 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/LASTDIG/
   
   * Status : AC

   ==========================================*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  long long t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    long long d = 1, pow = a % 10;
    while (b) {
      if (b & 1LL) {
        d *= pow;
        d %= 10;
      }
      pow *= pow;
      pow %= 10;
      b >>= 1;
    }
    cout << d << endl;
  }
  return 0;
}
