/* ========================================

   ID: mathema6
   TASK: ride
   LANG: C++11
   (...for USACO solutions)

   * File Name : ride.cpp

   * Creation Date : 28-12-2014

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://cerberus.delosent.com:791/usacoprob2?a=4Ua3TNbF5jF&S=ride

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
#include <fstream>

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

int main() {
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  string name;

  fin >> name;
  int mod1 = 1;
  for (char c : name) {
    mod1 *= c - 'A' + 1;
    mod1 %= 47;
  }

  fin >> name;
  int mod2 = 1;
  for (char c : name) {
    mod2 *= c - 'A' + 1;
    mod2 %= 47;
  }

  if (mod1 == mod2) {
    fout << "GO";
  } else {
    fout << "STAY";
  }
  fout << endl;

  return 0;
}
