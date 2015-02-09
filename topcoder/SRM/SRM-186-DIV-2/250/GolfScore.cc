/* ========================================
 * Points : 235.58
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class GolfScore {
public:
  int tally(vector <int> parValues, vector <string> scoreSheet) {
    int result = 0;
    int n = parValues.size(), x;
    REP(i,n) {
      if (scoreSheet[i] == "hole in one" ) { 
        result += 1;
        continue;
      }
      x = parValues[i];
      if (scoreSheet[i] == "triple bogey") x += 3; 
      if (scoreSheet[i] == "double bogey") x += 2; 
      if (scoreSheet[i] == "bogey"       ) x += 1; 
      if (scoreSheet[i] == "par"         ) x += 0; 
      if (scoreSheet[i] == "birdie"      ) x -= 1; 
      if (scoreSheet[i] == "eagle"       ) x -= 2; 
      if (scoreSheet[i] == "albatross"   ) x -= 3; 
      result += x;
    }

    return result;
  }
};
