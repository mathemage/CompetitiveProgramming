/* ========================================

   ID: mathema6
   TASK: samer08f
   LANG: C++11
   (...for USACO solutions)

   * File Name : samer08f.cpp

   * Creation Date : 06-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/SAMER08F/

   * Duration : 11 min

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
  int n;
  scanf("%d", &n);
  while (n != 0) {
    printf("%d\n", n * (n+1) * (2*n+1) / 6);
    scanf("%d", &n);
  }
  return 0;
}
