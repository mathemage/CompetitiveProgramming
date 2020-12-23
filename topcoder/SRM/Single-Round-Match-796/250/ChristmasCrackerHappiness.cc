/* ========================================
 * Points : 153.93
 * Total : 250
 * Status :
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

//#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;


class ChristmasCrackerHappiness {
public:
  int solve(int N, vector <int> winner, vector <int> loser) {
    vector<bool> happy(N,false);
    int n_losers = N;
    for (auto & w: winner) {
      if (!happy[w]) {
        happy[w] = true;
        n_losers--;
      }
    }
    return max(0, n_losers-1);
  }
};
