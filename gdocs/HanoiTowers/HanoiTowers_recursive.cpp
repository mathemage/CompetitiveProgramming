/* ========================================

   * File Name : HanoiTowers.cpp

   * Creation Date : 25-12-2014

   * Last Modified : Thu 25 Dec 2014 05:18:07 PM CET

   * Created By : Karel Ha <mathemage@gmail.com>

   * Source : Cracking the Code, page 118

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

void moveDisks(int n, int src, int dest) {
  if (n < 1)
    return;
  else if (n == 1)
    cout << "Disk #" << n << " from " << src << " to " << dest << endl;
  else {
    int tmp = 6 - src - dest;
    moveDisks(n-1,src,tmp);
    cout << "Disk #" << n
         << " from " << src
         << " to " << dest << endl;
    moveDisks(n-1,tmp,dest);
  }
}

void HanoiTowers(int n) {
  moveDisks(n,1,3);
} 

int main() {
  int disks;

  REP(i,5) {
    disks = i;
    cout << disks << " disks:" << endl;
    HanoiTowers(disks);
  }
}
