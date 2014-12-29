/* ========================================

   ID: mathema6
   TASK: nsteps
   LANG: C++11
   (...for USACO solutions)

   * File Name : nsteps.cpp

   * Creation Date : 29-12-2014

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL :

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
#include <fstream>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

int main() {
  int n, x, y;
  cin >> n;
  REP(i,n) {
    cin >> x >> y;
    if (x != y && x != y+2)
      cout << "No Number" << endl;
    else
      cout << x+y-(x%2) << endl;
  }

  return 0;
}
