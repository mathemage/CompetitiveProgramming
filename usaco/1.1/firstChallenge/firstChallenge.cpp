/* ========================================

    ID: mathema6
    TASK: test
    LANG: C++11

   * File Name : firstChallenge.cpp

   * Creation Date : 27-12-2014

   * Last Modified : Sat 27 Dec 2014 02:12:33 PM CET

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

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

// uncomment following line for debug mode
// #define DEBUG   

int main() {
  ofstream fout ("test.out");
  ifstream fin ("test.in");
  int a, b;
  fin >> a >> b;
  fout << a+b << endl;
  return 0;
}
