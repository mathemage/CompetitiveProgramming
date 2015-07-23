/* ========================================
 * Points : 242.62
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class CucumberMarket {
public:
  string check(vector <int> price, int budget, int k) {
    string result;
    sort(ALL(price));
    reverse(ALL(price));
    MSG(accumulate( price.begin(), price.begin() + k, 0));
    if (accumulate( price.begin(), price.begin() + k, 0) > budget) {
      result = "NO";
    } else {
      result = "YES";
    }

    return result;
  }
};
