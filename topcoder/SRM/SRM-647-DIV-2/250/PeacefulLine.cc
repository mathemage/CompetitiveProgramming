/* ========================================
 * Points : 125.55
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class PeacefulLine {
public:
  string makeLine(vector <int> x) {
    vector<int> cnt(26);
    for (auto & n : x) {
      cnt[n]++;
    }
    int m = *max_element(ALL(cnt));
    if (m <= x.size()-m+1)
      return "possible";
    else
      return "impossible";
  }
};
