/* ========================================
 * Points : 242.95
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class BettingMoney {
public:
  int moneyMade(vector <int> amounts, vector <int> centsPerDollar, int finalResult) {
    int result = accumulate(ALL(amounts), 0);
    result -= amounts[finalResult];
    result *= 100;
    result -= centsPerDollar[finalResult] * amounts[finalResult];

    return result;
  }
};
