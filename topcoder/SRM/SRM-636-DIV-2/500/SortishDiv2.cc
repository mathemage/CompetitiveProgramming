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

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

class SortishDiv2 {
public:
  int getSortedness(vector<int> & s) {
    int res = 0;
    REP(i,s.size()) {
      FOR(j,i+1,s.size()) {
        res += (s[i] < s[j]) ? 1 : 0;
      }
    }
    return res;
  }

  void display(vector<int> v) {
    REP(i,v.size()) {
      cout << v[i] << " ";
    }
    cout << endl;
  }

  int ways(int sortedness, vector <int> seq) {
    int result = 0;
    int sz = seq.size();
    vector<bool> missing(sz,true);
    vector<int> pos;
    REP(i,sz) {
      if (seq[i] == 0) {
        pos.push_back(i);
      } else {
        missing[seq[i]-1] = false;
      }
    }

    vector<int> m;
    REP(i,sz) {
      if (missing[i])
        m.push_back(i+1);
    }
    int ms = m.size();
    //sort(ALL(m));

    do {
      //cout << "m: ";
      //display(m);
      REP(i,ms) {
        seq[pos[i]] = m[i];
      }
      result += (getSortedness(seq) == sortedness) ? 1 : 0;

      //cout << "seq: ";
      //display(seq);
    } while (next_permutation(ALL(m)));
    
    return result;
  }
};

// 287.95/500 pts