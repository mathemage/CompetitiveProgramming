/* ========================================
 * Points :
 * Total :
 * Status : arena failed
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

using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

// uncomment following line for debug mode
#define DEBUG

#ifdef DEBUG
#define MSG(a) cout << #a << " == " << a << endl;
#else
#define MSG(a) ;
#endif

class LostCharacter {
public:
  vector <int> getmins(vector <string> str) {
    int n = str.size();
    vector <int> result(n);

    REP(i,n) {
      string a = str[i];
      for (char & c : a) {
        if (c == '?') c = 'a';
      }
      REP(j,n) {
        if (j == i) continue;

        string b = str[j];
        for (char & c : b) {
          if (c == '?') c = 'z';
        }

        if (a.compare(b) > 0) {
          result[i]++;
        }
      }
    }
    return result;
  }
};
