/* ========================================
 * Points : 239.84
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class ScoringEfficiency {
public:
  double getPointsPerShot(vector <string> gameLog) {
    int total = 0;
    int field = 0;
    int free = 0;

    for (auto & x : gameLog) {
      if (x == "Made 2 point field goal") {
        field++;
        total += 2;
      }
      if (x == "Missed 2 point field goal") {
        field++;
      }
      if (x == "Made 3 point field goal") {
        field++;
        total += 3;
      }
      if (x == "Missed 3 point field goal") {
        field++;

      }
      if (x == "Made free throw") {
        free++;
        total += 1;
      }
      if (x == "Missed free throw") {
        free++;

      }
    }

    return double(total / (field + 0.5 * free) );
  }
};
