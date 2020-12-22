/* ========================================
 * Points : 173.45 - 135.63 - 103.05 - 75.00
 * Total : 250
 * Status : WA (#13) - WA (#13) - WA (#13) - AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

//#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;


class DivideLoot {
public:
  string verify(int N, vector <int> loot) {
    int needed = accumulate(ALL(loot), 0);
    if (needed % N) {
      return "impossible";
    }
    needed /= N;

    int K = loot.size();
    vector<bool> assigned(K,false);
    int n_assigned = 0;
    REP(i,K) {
      if (assigned[i]) {
        continue;
      }

      MSG(i) MSG(loot[i]);
      if (loot[i] == needed) {
        assigned[i] = true;
        n_assigned++;
      } else if (loot[i] > needed) {
        return "impossible";
      } else {
        FOR(j,i+1,K) {
          MSG(j) MSG(loot[j]) MSG(loot[i] + loot[j]);
          if (loot[i] + loot[j] == needed && !assigned[j]) {
            MSG(needed);
            assigned[i] = true;
            assigned[j] = true;
            n_assigned += 2;
            break;
          }
        }
      }
      MSG(n_assigned);
    }

    return (n_assigned == K ? "possible" : "impossible");
  }
};
