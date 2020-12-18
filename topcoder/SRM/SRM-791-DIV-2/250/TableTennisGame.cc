/* ========================================
 * Points : 75.05 - 75.00 - 75.00
 * Total : 250
 * Status : WA (#7) - AC - 
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

//#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;


class TableTennisGame {
public:
  vector <int> finalScore(int A, int B) {
    int P1 = max(A,B);
    int P2 = min(A,B);

    if (P1 >= 10 && P2 >= 10) {
      if (P1 == P2) {
        return {P1 + 1, P2 - 1};
      }
    } else {
      if (P1 - P2 <= 2 && ((P1 * P2) & 1) ^ 1) {
//       if (P1 - P2 <= 2 && !((P1 * P2) % 2)) {
        int L = P1 + P2 - 11;
        if (L >= 0) {
          return {11, L};
        }
      }
    }

    return { };
  }
};
