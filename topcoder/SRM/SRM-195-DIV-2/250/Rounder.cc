/* ========================================
 * Points : 215.75
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Rounder {
public:
  int round(int n, int b) {
    int result = (n / b) * b;
    MSG(result);
    if (n - result > (b-1)/2 ) result += b;

    return result;
  }
};
