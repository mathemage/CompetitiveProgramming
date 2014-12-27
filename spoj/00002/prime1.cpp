/* ========================================

   * File Name : prime1.cpp

   * Creation Date : 26-12-2014

   * Last Modified : Sat 27 Dec 2014 03:53:11 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/PRIME1/

   * Duration : cca 2 hours

   ==========================================*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>
#include <cctype>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

void printPrimes(int m, int n) {
  vector<bool> sieve(n-m+1, true);
  FOR(k,m,n+1) {
    if (k == 1)
      sieve[0] = false;
    if (!sieve[k-m])
      continue;

    int divisor = 2;
    int l = k;
    while (divisor * divisor <= l) {
      bool divisible = false;
      while (l % divisor == 0) {
        l /= divisor;
        divisible = true;
      }

      if (divisible) {    // eliminate multiples in sieve
        for (int i = k; i <= n; i += divisor) {
          sieve[i-m] = false;
        }
      }
      divisor += (divisor == 2) ? 1 : 2;
    }
  }

  FOR(k,m,n+1) {
    if (sieve[k-m])
      cout << k << endl;
  }
}

int main() {
  int t, m, n;
  cin >> t;

  REP(i,t) {
    cin >> m >> n;
    printPrimes(m, n);
    if (i < t-1)
      cout << endl;
  }

  return 0;
}
