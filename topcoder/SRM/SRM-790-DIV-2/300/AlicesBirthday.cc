/* ========================================
 * Points : 151.39
 * Total : 300
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define RFOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;


class AlicesBirthday {
public:
  vector <int> partition(int k) {
    long long sum = 1L;
    vector<int> F(1+k);
    F[0] = 0;
    F[1] = 1;
    FOR(i,2,k+1) {
      F[i] = F[i-2] + F[i-1];
      sum += F[i];
    }

    if (sum%2) {
      return {-1};
    }
    sum /= 2;

    vector <int> result;
    RFOR(i,k+1,1) {
//       cerr << endl; MSG(i); MSG(F[i]); MSG(sum);
      if (F[i] <= sum) {
        result.push_back(i);
        sum -= F[i];
//         MSG(sum);
      }
    }
    
    return ((sum) ? vector<int> {-1} : result);
//     if (sum) {
//       return {-1};
//     } else {
//       return result;
//     }
  }
};
