/* ========================================
 * Points : 180.57
 * Total : 250
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class BacteriesColony {
public:
  vector <int> performTheExperiment(vector <int> colonies) {
    int n = colonies.size();
    vector<int> result;

    int ch;
    do {
      ch = 0;
      result = colonies;
      FOR(i,1,n-1) {
        MSG(i)
        if (colonies[i-1] > colonies[i] && colonies[i+1] > colonies[i]) {
          result[i]++;
          ch = 1;
        }
        if (colonies[i-1] < colonies[i] && colonies[i+1] < colonies[i]) {
          result[i]--;
          ch = 1;
        }
        MSG(ch)
        MSG(result[i])
      }
      for (auto & x : result) {
        cout << x << " ";
      }
      cout << endl;
      MSG(ch)
      colonies = result;
      if (ch == 0)
        break;
    } while (true);

    return result;
  }
};
