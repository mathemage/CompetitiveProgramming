/* ========================================

ID: mathema6
TASK: circus
LANG: C++11
(...for USACO solutions)

 * File Name : circus.cpp

 * Creation Date : 01-01-2015

 * Last Modified :

 * Created By : Karel Ha <mathemage@gmail.com>

 * Problem statement :
 *
 * A circus is designing a tower routine consisting of people standing atop one
 * another's shoulders. For practical and aesthetic reasons, each person must
 * be both shorter and lighter than the person below him or her. Given the
 * heights and weights of each person in the circus, write a method to compute
 * the largest possible number of people in such a tower.

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
#define DEBUG   

struct hw {
  int h, w;
};

inline bool operator<(const hw& lhs, const hw& rhs){
  return (lhs.h < rhs.h) || (lhs.h == rhs.h && lhs.w < rhs.w);
}

void show(const vector<hw> & seq) {
  REP(i,seq.size()) {
    cout << "(" << seq[i].h << ", " << seq[i].w << ") ";
  }
  cout << endl;
}

vector<hw> getMaxSeq(vector<hw> & seq) {
#ifdef DEBUG
  cout << "orig seq: ";
  show(seq);
#endif
  
  int n = seq.size(), maxL = 0, maxP;
  vector<int> l(n);
  vector<int> p(n);
  REP(i,n) {
    p[i] = i;
    REP(j,i) {
      if (seq[j].w <= seq[i].w && l[j] > l[i]) {
        l[i] = l[j];
        p[i] = j;
      }
    }
    l[i]++;

    if (maxL < l[i]) {
      maxL = l[i];
      maxP = i;
    }
  }

  vector<hw> result;
  while (maxP != p[maxP]) {
    result.push_back(seq[maxP]);
    maxP = p[maxP];
  }
  result.push_back(seq[maxP]);
  reverse(ALL(result));

#ifdef DEBUG
  MSG(maxL)
#endif
  return result;
}

int main() {
  int t, n, h, w;
  cin >> t;
  
  while(t--) {
    cin >> n;
    vector<hw> people(n);
    REP(i,n) {
      cin >> people[i].h >> people[i].w;
    }

    sort(ALL(people));
    show(getMaxSeq(people));
  }
  return 0;
}
