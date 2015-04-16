/* ========================================
 * Points : 245.30
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Soccer {
public:
  int maxPoints(vector <int> wins, vector <int> ties) {
    int n = wins.size();
    vector<int> s(n);
    REP(i,n) {
      s[i] = 3 * wins[i] + ties[i];
    }

    return *max_element(ALL(s));
  }
};
