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

class LightSwitchingPuzzle {
public:
  void toggle(string & s, int t) {
    MSG(t)
    for (int i = t; i <= s.size(); i+=t) {
      s[i-1] = (s[i-1] == 'Y') ? 'N' : 'Y';
      MSG(i)
    }
    MSG(s)
  }

  int minFlips(string state) {
    int result = 0;
    string off(state.size(),'N');

    int i;
    while (state.compare(off) != 0) {
      MSG(state) MSG(off)
      i = 0;
      while (i < state.size() && state[i] != 'Y')
        i++;

      if (i < state.size()) {
        result++;
        cout << "before: " << endl;
        MSG(state)
        cout << "after: " << endl;
        toggle(state, i+1);
      }
      cout << "hey!" << endl;
    }
    return result;
  }
};

// 267.68/500 
