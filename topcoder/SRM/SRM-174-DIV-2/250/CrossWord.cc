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

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;

class CrossWord {
public:
  int countWords(vector <string> board, int size) {
    int result = 0;
    for (string r : board) {
      int curLine = 0;
      for (char c : r) {
        if (c == '.') {
          curLine++;
        } else {
          result += curLine == size;
          curLine = 0;
        }
      }
      result += curLine == size;
    }

    return result;
  }
};

// 230.09/250
