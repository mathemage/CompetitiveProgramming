/* ========================================

ID: mathema6
TASK: brackets
LANG: C++11
(...for USACO solutions)

 * File Name : brackets.cpp

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

vector<string> brackets(int n) {
  vector<string> res;
  //MSG(n)
  if (n > 0) {
    vector<string> vs = brackets(n-1);
    //MSG(vs.size())
    for (string w : vs) {
      res.push_back("(" + w + ")");
      if (!w.empty()) {
        res.push_back("()" + w);
        res.push_back(w + "()");
      }
    }
  } else {
    res.push_back("");
  }
  sort(ALL(res));
  res.erase( unique(ALL(res)), res.end() );
  return res;
}

int main() {
  int n;
  cin >> n;
  for (string w : brackets(n)) {
    cout << w << endl;
  }
  return 0;
}
