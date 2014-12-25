/* ========================================

   * File Name : B.cpp

   * Creation Date : 24-12-2014

   * Last Modified : Wed 24 Dec 2014 08:31:15 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/499/problem/B

   * Points Gained (in case of online contest) : 452

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
#include <unordered_map>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

int main() {
  int n, m;
  cin >> n >> m;

  unordered_map<string,string> dic;
  string w1, w2, val;
  REP(i,m) {
    cin >> w1 >> w2;

    if (w2.size() < w1.size())
      val = w2;
    else
      val = w1;
    dic[w1] = val;
  }

  REP(i,n) {
    cin >> w1;
    cout << dic[w1];
    if (i < n-1)
      cout << " ";
  }
}
