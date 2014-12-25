/* ========================================

   * File Name : D.cpp

   * Creation Date : 24-12-2014

   * Last Modified : Wed 24 Dec 2014 10:49:31 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://codeforces.com/contest/499/problem/D

   * Points Gained (in case of online contest) : not submitted

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
//#define DEBUG   

double solve(int song, int T, vector<vector<double>> & E, vector<double> & p, vector<int> & t) {
  MSG(song) MSG(T)
  cout << "----------" << endl;
  double a, b;
  if (T == 1)
    return p[song];
  a = p[song] * (1 + solve(song+1, T-1, E, p, t));
  b = (1-p[song]) * solve(song, T-1, E, p, t);
  return a + b;
}

int main() {
  int n, T;
  cin >> n >> T;
  vector<double> p(n);
  vector<int> t(n);

  REP(i,n) {
    cin >> p[i] >> t[i]; 
    p[i] /= 100;
  }

  vector<vector<double>> E(n);
  REP(i,n) {
    E[i].assign(T+1, 0.0);    // 2nd index == time to chorus
  }

  /*
  // init DP
  E[n-1][0] = p[n-1];
  FOR(i,1,t[i]) {
    E[n-1][i] = p[i] + (1-p[i]) * E[n-1][i-1];
  }
  FOR(i,t[i],T+1) {
    E[n-1][i] = 1;
  }
  
  for (int i = n-2; i >= 0; i--) {
    REP(j,T+1) {
      E[i][j] = (1-p[i]) * E[i][j-1] + p[i] * E[i+1][ min(t[i+1],T) ];
    }
  }
  */

  cout << solve(0,T,E,p,t) << endl;

#ifdef DEBUG
  REP(i,n) {
    REP(j,T+1)
      cout << E[i][j] << "\t";
    cout << endl;
  }
#endif
}
