/* ========================================

   ID: mathema6
   TASK: gift1
   LANG: C++11
   (...for USACO solutions)

   * File Name : gift1.cpp

   * Creation Date : 29-12-2014

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

int main() {
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");

  int np;
  fin >> np;
  string w;
  unordered_map<string,int> bal;
  vector<string> names(np);
  REP(i,np) {
    fin >> w;
    names[i] = w;
    bal[w] = 0;
  }

  string giver;
  int ng, recipients, share;
  REP(i,np) {
    fin >> giver >> ng >> recipients;
    share = (recipients == 0) ? 0 : (ng / recipients);
    bal[giver] -= share * recipients;
    REP(j,recipients) {
      fin >> w;
      bal[w] += share;
    }
  }

  for (string name : names) {
    fout << name << " " << bal[name] << endl;
  }
  return 0;
}
