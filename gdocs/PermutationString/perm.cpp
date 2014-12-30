/* ========================================

   ID: mathema6
   TASK: perm
   LANG: C++11
   (...for USACO solutions)

   * File Name : perm.cpp

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

class Permutator {
  private:
    string in;
  public:
    Permutator(string _in) : in(_in) {}

    void printPerms() {
      printPerms(0);
    }

    void printPerms(int start) {
      if (start >= in.size() - 1) {
        cout << in << endl;;
        return;
      }
      FOR(i,start,in.size()) {
        //MSG(start) MSG(i)
        swap(in[start], in[i]);
        printPerms(start+1);
        swap(in[start], in[i]);
      }
    }
};

int main() {
  string w;
  cin >> w;
  Permutator pm(w);
  pm.printPerms();
  return 0;
}
