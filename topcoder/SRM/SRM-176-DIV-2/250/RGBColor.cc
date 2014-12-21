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

class RGBColor {
public:
  vector <int> getComplement(vector <int> rgb) {
    vector <int> result(3);
    vector <int> result2(3);
    bool ok = false;
    REP(i,3) {
      result[i] = 255 - rgb[i];
      result2[i] = rgb[i] + 128 * ( (rgb[i] < 128) ? 1 : -1 );
      if (abs(result[i] - rgb[i]) > 32) {
        ok = true;
      }
    }

    return (ok) ? result : result2;
  }
};

// 171.37/250
