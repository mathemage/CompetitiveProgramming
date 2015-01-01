/* ========================================

ID: mathema6
TASK: circus
LANG: C++11
(...for USACO solutions)

 * File Name : circus.cpp

 * Creation Date : 01-01-2015

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

int forcedUnfitSeq(const vector<hw> & seq, vector<hw> & newSeq, int firstUnfit) {
  newSeq.clear();
  REP(i,firstUnfit) {
    if (seq[i].w <= seq[firstUnfit].w)
      newSeq.push_back(seq[i]);
  }

  int newUnfit = seq.size();
  FOR(i, firstUnfit, seq.size()) {
    if (newSeq.empty() || newSeq.back().w <= seq[i].w) {
      newSeq.push_back(seq[i]);
    } else {
      newUnfit = min(newUnfit, i);
    }
  }

  return newUnfit;
}

vector<hw> getMaxSeq(vector<hw> & seq) {
  int firstUnfit = 0;
  vector<hw> result;
  vector<hw> newSeq;
#ifdef DEBUG
  cout << "seq: ";
  show(seq);
#endif
  
  while (firstUnfit < seq.size()) {
    firstUnfit = forcedUnfitSeq(seq, newSeq, firstUnfit);
#ifdef DEBUG
    cout << "newSeq: ";
    show(newSeq);
    MSG(firstUnfit)
    MSG(seq.size())
#endif

    if (result.empty() || result.size() < newSeq.size()) {
      result = newSeq;
    }
  }

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
