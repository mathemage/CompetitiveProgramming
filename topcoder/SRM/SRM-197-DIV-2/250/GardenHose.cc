/* ========================================
 * Points : 111.56
 * Total : 250
 * Status : AC on #2
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class GardenHose {
public:
  int countDead(int n, int rowDist, int colDist, int hoseDist) {
    int r = min(n, 2 * (hoseDist / rowDist));
    int c = min(n, 2 * (hoseDist / colDist));

    int res = n * n - r * n - c * (n - r);
    return res;
  }
};
