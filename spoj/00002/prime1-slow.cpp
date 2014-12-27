/* ========================================

   * File Name : prime1.cpp

   * Creation Date : 26-12-2014

   * Last Modified : Sat 27 Dec 2014 11:39:36 AM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/PRIME1/

   * Points Gained (in case of online contest) :

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

bool isPrime(int k) {
  if (k == 1)
    return false;

  int divisor = 2;
  while (divisor * divisor <= k) {
    if (k % divisor == 0) {
      return false;
    }
    divisor += (divisor == 2) ? 1 : 2;
  }
}

int main() {
  int t, m, n;
  cin >> t;

  REP(i,t) {
    cin >> m >> n;
    FOR(k,m,n+1) {
      if (isPrime(k))
        cout << k << endl;
    }
    if (i < t-1)
      cout << endl;
  }

  return 0;
}
