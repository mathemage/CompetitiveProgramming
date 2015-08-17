/* ========================================

   ID: mathema6
   TASK: tsort
   LANG: C++11
   (...for USACO solutions)

   * File Name : tsort.cpp

   * Creation Date : 27-12-2014

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.codechef.com/problems/TSORT

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

int main() {
  int t;
  cin >> t;
  vector<int> nums(t);
  int mx = 0;
  REP(i,t) {
    scanf("%d", &nums[i]);
    mx = max(mx, nums[i]);
  }

  vector<int> counts(++mx);
  for (int n : nums) {
    counts[n]++;
  }

  REP(i,mx) {
    REP(j,counts[i]) {
      printf("%d\n", i);
    }
  }
  return 0;
}
