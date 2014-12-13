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


class NamingConvention {
public:
  string toCamelCase(string variableName) {
    string res;
    bool cap = false;

    for (char c : variableName) {
      if (c == '_') cap = true;
      else if (cap) {
        res += c - 'a' + 'A';
        cap = false;
      } else {
        res += c;
      }
    }

    return res;
  }
};