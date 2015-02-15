/* ========================================
 * Points : 287.85
 * Total : 300
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class CutoffRounder {
public:
  int round(string num, string cutoff) {
    stringstream ss;
    ss.str(num);
    double d, c;
    ss >> d;
    ss.clear();
    ss.str(cutoff);
    ss >> c;
    int result = floor(d);
    if (d - floor(d) > c) result++;

    return result;
  }
};
