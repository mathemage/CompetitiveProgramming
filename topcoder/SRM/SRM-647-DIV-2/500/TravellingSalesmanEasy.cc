/* ========================================
 * Points : 289.99
 * Total : 500
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class TravellingSalesmanEasy {
public:
  int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit) {
    int g = profit.size();
    vector<pair<int, int>> goods(g);
    REP(i,g) {
      goods[i] = {city[i], -1 * profit[i]};
    }
    sort(ALL(goods));
    sort(ALL(visit));

    REP(i,g) {
      MSG(goods[i].first)
      MSG(goods[i].second)
    }
    for (int i = 0; i <  visit.size(); ++i) {
      MSG(visit[i])
    }

    vector<int> cnt(M);
    for (auto & x : visit) {
      cnt[x-1]++;
    }

    int result = 0;
    REP(i,M) {
      if (cnt[i] > 0) {
        MSG(i+1) MSG(cnt[i])
        int j = 0;
        while (j < g && goods[j].first != i+1) j++;
        MSG(j)
        while (cnt[i]-- > 0 && j < g && goods[j].first == i+1) {
          result -= goods[j].second;
          j++;
        }
        MSG(result) cout << endl;
      }
    }

    return result;
  }
};
