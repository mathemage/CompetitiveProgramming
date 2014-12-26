/* ========================================

   * File Name : fctrl2.cpp

   * Creation Date : 25-12-2014

   * Last Modified : Fri 26 Dec 2014 11:25:53 AM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://www.spoj.com/problems/FCTRL2/

   * Duration : 

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
//#define DEBUG   

#define SZ 200

vector<short> tmp(SZ);
vector<short> res(SZ);

void display(vector<short> & v) {
  int i = SZ-1;
  while (i >= 0 && v[i] == 0) {
    i--;
  }
  while (i >= 0) {
    cout << v[i];
    i--;
  }
}

void add(vector<short> & u, vector<short> & v, vector<short> & w) {
  short carry = 0;
  short tmp;
  REP(i,SZ) {
    tmp = u[i] + v[i] + carry;
    w[i] = tmp % 10;
    carry = tmp / 10;
  }
}

void mult(vector<short> & v, int n) {
  res.assign(SZ,0);
  int startPos = 0;
  while (n) {
    short digit = n%10;
    short carry = 0;
    tmp.assign(SZ,0);

    REP(i,SZ) {
      tmp[startPos + i] = (digit * v[i] + carry) % 10;
      carry = (digit * v[i] + carry) / 10;
    }
    
    add(res, tmp, res);
    n /= 10;
    startPos++;
  }
  v = res;
}

void fact(int n) {
  vector<short> fac(SZ, 0);
  fac[0] = 1;
  while (n > 1) {
    mult(fac, n);
    n--;
  }
  display(fac);
}

int main() {
  int t, n;
  cin >> t;
  REP(i,t) {
    cin >> n;
    fact(n);
    cout << endl;
  }
}
