/* ========================================

   ID: mathema6
   TASK: tlg
   LANG: C++11
   (...for USACO solutions)

   * File Name : tlg.cpp

   * Creation Date : 31-12-2014

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.codechef.com/problems/TLG/

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
#include <fstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

int main() {
  int n, s, t, a, b;
  s = t = 0;
  int w, l = 0, d;

  cin >> n;
  REP(i,n) {
    cin >> a >> b;
    s += a;
    t += b;
    d = abs(s-t);
    if (d > l) {
      l = d;
      w = (s > t) ? 1 : 2;
    }
  }
  cout << w << " " << l;
  return 0;
}
