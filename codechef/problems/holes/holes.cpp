/* ========================================

   * File Name : holes.cpp

   * Creation Date : 23-12-2014

   * Last Modified : Tue 23 Dec 2014 09:52:00 PM CET

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
#include <regex>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

inline int countOfHoles(string str) {
  int count = 0;
  for (char c : str) {
    switch (c) {
      case 'A':
      case 'D':
      case 'O':
      case 'P':
      case 'Q':
      case 'R':
        count += 1;
        break;
      case 'B':
        count += 2;
        break;
    }
  }
  return count;
}

int main() {
  int t;
  cin >> t;

  string line;
  while (t--) {
    cin >> line;
    cout << countOfHoles(line) << endl;
  }
  return 0;
}
