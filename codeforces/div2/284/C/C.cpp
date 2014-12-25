/* ========================================

   * File Name : C.cpp

   * Creation Date : 25-12-2014

   * Last Modified : Thu 25 Dec 2014 07:05:26 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/499/problem/C

   * Points Gained (in case of online contest) : 0 (about 12 mins of coding,
   * had to debug because of problem with multiplying sings - perhaps overflow
   * problem)

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
  long long int x1,y1,x2,y2,n;
  cin >> x1 >> y1 >> x2 >> y2 >> n;
  
  long long int res = 0;
  long long int a,b,c;
  REP(i,n) {
    cin >> a >> b >> c;
    if ( (a*x1 + b*y1 + c) > 0 && (a*x2 + b*y2 + c) < 0 )
      res++;
    if ( (a*x1 + b*y1 + c) < 0 && (a*x2 + b*y2 + c) > 0 )
      res++;
  }
  cout << res;
}
