/* ========================================
 * Points :
 * Total : 500
 * Status : not submitted
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

//#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;


class ChristmasLightsFixing {
public:
  long long comb(n, k) {
    long long result = 1;
    FOR(i,1,k+1) {
      result *= n / i;
      n--;
    }
    return result;
  }
  vector <int> fixingTime(int N, long long step) {
    long long choices = N;
    long long set_width = 1;
    while (step) {
      long long combinations = comb(choices, set_width);
      if (step > combinations) {
        step -= combinations;
      } else {  # lexo
        break;
      }

      set_width++;
    }

    vector <int> result(set_width);
    REP(pos,set_width) {
    REP(i,N) {
      long long combinations = comb(choices, set_width);
      if (step > combinations) {
        step -= combinations;
      } else {  # lexo
        break;
      }

      set_width++;
    }

    return result;
  }
};
