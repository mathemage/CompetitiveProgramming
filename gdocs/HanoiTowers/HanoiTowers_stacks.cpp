/* ========================================

   * File Name : HanoiTowers.cpp

   * Creation Date : 25-12-2014

   * Last Modified : Thu 25 Dec 2014 06:30:08 PM CET

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

class Rod {
  stack<int> tow;
  int label;
  public:
    void setLabel(int i) {
      label = i;
    }

    void push(int disk) {
      tow.push(disk);
      cout << "disk #" << disk << " -> rod #" << label << endl;
    }

    int pop() {
      if (tow.empty()) {
        cerr << "rod #" << label << " is empty" << endl;
        throw;
      }
      int disk = tow.top();
      tow.pop();
      cout << "disk #" << disk << " <- rod #" << label << endl;
      return disk;
    }
};

void moveDisks(int n, int src, int dest, Rod *rods) {
  if (n < 1)
    return;

  int tmp = 3 - src - dest;
  if (n > 1) {
    moveDisks(n-1,src,tmp,rods);
  }

  rods[dest].push( rods[src].pop() );

  if (n > 1) {
    moveDisks(n-1,tmp,dest,rods);
  }
}

void HanoiTowers(int n) {
  Rod rods[3];
  for (int i = 0; i < 3; i++) {
    rods[i].setLabel(i+1);
  }

  cout << "Initial push phase..." << endl;
  for (int i = 0; i < n; i++) {
    rods[0].push(i+1);
  }
  cout << "Done!" << endl;

  moveDisks(n,0,2,rods);
} 

int main() {
  int disks;

  REP(i,5) {
    disks = i;
    cout << disks << " disks:" << endl;
    HanoiTowers(disks);
    cout << endl;
  }
}
