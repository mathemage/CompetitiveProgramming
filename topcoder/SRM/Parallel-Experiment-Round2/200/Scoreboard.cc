/* ========================================
 * Points : 193.32
 * Total : 200
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Scoreboard {
public:
  int getScore(string events) {
    int result = 0;

    for (auto & x : events) {
      switch (x) {
        case 'B':
          result += 1000; break;
        case 'b':
          result += 250; break;
        case 'R':
          result += 50; break;
        case 'J':
          result += 10000; break;
        case 'D':
          result += 20000; break;
      }
    }
    return result;
  }
};
