/* ========================================

   * File Name : A.cpp

   * Creation Date : 24-12-2014

   * Last Modified : Wed 24 Dec 2014 08:31:31 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/499/problem/A

   * Points Gained (in case of online contest) : 478

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
#include <regex>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

int main() {
  int n, x, r, l;
  cin >> n >> x;

  int current = 0, total = 0;
  REP(i,n) {
    cin >> l >> r;
    while (current < l - x)
      current += x;
    total += r - current;
    current = r;
  }
  cout << total;
}
