/* ========================================
 * Points : 238.61
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Education {
public:
  int minimize(string desire, vector <int> tests) {
    int result, m;
    switch (desire[0]) {
      case 'A':
        m = 90; break;
      case 'B':
        m = 80; break;
      case 'C':
        m = 70; break;
      case 'D':
        m = 60; break;
    }
    int n = tests.size();
    result = (n+1) * m - accumulate(ALL(tests), 0);

    if (result <= 100) {
      return max(result, 0);
    } else {
      return -1;
    }
  }
};
