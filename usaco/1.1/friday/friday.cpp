/* ========================================

   ID: mathema6
   TASK: friday
   LANG: C++11
   (...for USACO solutions)

   * File Name : friday.cpp

   * Creation Date : 03-01-2015

   * Last Modified :

   * Created By : Karel Ha <mathemage@gmail.com>

   * URL : http://cerberus.delosent.com:791/usacoprob2?a=nJinR3Por13&S=friday

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

bool isLeap(short year) {
  return (year % 400 == 0)
    || (year % 4 == 0 && year % 100 != 0);
}

int main() {
  ifstream fin ("friday.in");
                  // 31 28 31 30 31 30 31 31 30 31 30 31 
  short offset[12] = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3} ;
  int n;
  fin >> n;

  short day = 0;      // 13th Jan 1900
  vector<int> histogram(7);
  REP(year,n) {
    REP(month,12) {
      histogram[day]++;
      day += offset[month];
      if (month == 1 && isLeap(1900 + year))
        day++;
      day %= 7;
    }
  }

  ofstream fout ("friday.out");
  REP(i,7) {
    fout << histogram[i];
    if (i < 6) fout << " ";
    else fout << endl;
  }
  return 0;
}
