/* ========================================

   ID: mathema6
   TASK: A
   LANG: C++11
   (...for USACO solutions)

   * File Name : A.cpp

   * Creation Date : 30-12-2014

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
  int n,t;
  cin >> n >> t;
  int now = 1;
  int a;
  REP(i,n-1) {
    cin >> a;
    if (i+1 == now) {
      now += a;
    }
    if (now == t) {
      cout << "YES";
      break;
    }
    if (now > t) {
      cout << "NO";
      break;
    }
  }
  return 0;
}
