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

class PathGameDiv2 {
public:
  int calc(vector <string> board) {
    int result = 0;
    string types;
    for (int i = 0; i < board[0].size(); ++i) {
      if (board[0][i] == board[1][i])
        types += 'b';
      else if (board[0][i] == '.')
        types += 'u';
      else
        types += 'd';
    }
    
    types +=  'b';
    MSG(types)
    char row = '_';
    for (int i = 0; i < types.size(); ++i) {
      if (i > 0 && types[i-1] == 'b'
          && (types[i] == 'b' || types[i] == row || row == '_'))
        result++;

      if (types[i] != 'b')
        row = types[i];
    }
    
    return result;
  }
};

// 196.05 / 500 pts, systests failed
