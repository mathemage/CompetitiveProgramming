/* ========================================
 * Points : 235.84
 * Total : 256
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class TheExperimentDiv2 {
public:
  vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd) {
    int m = leftEnd.size();
    vector <int> result(m);
    REP(spng,m) {
      FOR(drop,leftEnd[spng],leftEnd[spng]+L) {
        result[spng] += intensity[drop];
        intensity[drop] = 0;
      }
    }

    return result;
  }
};
