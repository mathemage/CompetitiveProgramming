/* ========================================
 * Points : 238.75
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class MagicSquare {
public:
  int missing(vector <int> s) {
    /* 
    int a = accumulate(square, square+3, 0);
    int b = accumulate(square+3, square+6, 0);
    int c = accumulate(square+6, square+9, 0);
 */
    int a = s[0] + s[1] + s[2];
    int b = s[3] + s[4] + s[5];
    int c = s[6] + s[7] + s[8];
    int x = min(a, min(b,c));
    int y = max(a, max(b,c));

    return (y-x)-1;
  }
};
