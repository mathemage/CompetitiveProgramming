/* ========================================
 * Points : 414.59
 * Total : 500
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define ENDL "\n"
#define FO(I,A,B) for(int I = (A); I <= (B); ++I)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;


class OrganicChemistry {
public:
  int countHydrogens(string atoms, vector <int> X, vector <int> Y) {
    int m = X.size();

    vector<int> avail;
    for (auto & a : atoms) {
      if (a == 'O') {
        avail.push_back(2);
      }
      if (a == 'N') {
        avail.push_back(3);
      }
      if (a == 'C') {
        avail.push_back(4);
      }
    }

    REP(j,m) {
      avail[X[j]]--;
      avail[Y[j]]--;
    }

    int result = accumulate(ALL(avail), 0);;
    return result;
  }
};
