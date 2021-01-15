/* ========================================
 * Points : 472.05
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
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MINUPDATE(A,B) A = min((A), (B));
#define MAXUPDATE(A,B) A = max((A), (B));
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;


class PairedMultiples {
public:
  int selectedTotal(vector <int> values, int multiple) {
    int result = 0;
    for (int i = 0; i < values.size(); i += 1) {
      for (int j = 0; j < values.size(); j += 1) {
        if (i!=j && (values[i] + values[j]) % multiple == 0) {
          result += values[i];
          break;
        }
      }
    }
    return result;
  }
};
