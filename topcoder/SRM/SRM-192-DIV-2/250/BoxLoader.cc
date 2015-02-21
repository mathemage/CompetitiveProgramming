/* ========================================
 * Points : 221.39
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class BoxLoader {
public:
  int mostItems(int boxX, int boxY, int boxZ, int itemX, int itemY, int itemZ) {
    vector<int> b {boxX, boxY, boxZ};
    vector<int> i {itemX, itemY, itemZ};
    sort(ALL(i));
    int result = 0;
    do {
      int s = 1;
      REP(j,3) {
        s *= b[j] / i[j];
      }
      result = max(result, s);
      for (auto & x : i) {
        cout << x << " ";
      }
      cout << "== i[]\n";
      MSG(result);
    } while (next_permutation(ALL(i)));

    return result;
  }
};
