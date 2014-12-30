/* ========================================

   ID: mathema6
   TASK: B
   LANG: C++11
   (...for USACO solutions)

   * File Name : B.cpp

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
//#define DEBUG   

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  REP(i,n) {
    cin >> p[i];
  }

  vector<vector<bool>> A(n);
  string line;
  REP(i,n) {
    A[i].assign(n,false);
    cin >> line;
    REP(j,n) {
      A[i][j] = (line[j] == '0') ? false : true;
    }
  }

  // FW
  REP(k,n) {
#ifdef DEBUG
    // display A
    MSG(k)
    cout << "A:" << endl;
    REP(i,n) {
      REP(j,n) {
        cout << A[i][j] ? "1" : "0";
      }
      cout << endl;
    }
#endif

    REP(i,n) {
      REP(j,n) {
        A[i][j] = A[i][j] || (A[i][k] && A[k][j]);
      }
    }
  }

  REP(i,n-1) {
    int mi = n+1;
    int idx = i;
    FOR(j,i,n) {
      if (A[i][j] && p[j] < mi) {
        mi = p[j];
        idx = j;
      }
    }
    swap(p[i], p[idx]);
  }

  REP(i,n) {
    cout << p[i];
    if (i < n-1)
      cout << " ";
  }
  return 0;
}
