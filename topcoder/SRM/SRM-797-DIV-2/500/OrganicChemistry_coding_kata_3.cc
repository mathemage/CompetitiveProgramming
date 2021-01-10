/* ========================================
 * Points : 499.42
 * Total : 500
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

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
    int result=-2*X.size();
    for (auto & i : atoms) {
      result += i=='O'?2:0;
      result += i=='N'?3:0;
      result += i=='C'?4:0;
    }
    return result;
  }
};
