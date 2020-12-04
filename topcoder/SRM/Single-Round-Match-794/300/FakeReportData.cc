/* ========================================
 * Points : 152.07
 * Total : 300
 * Status : challenged
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

//#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;


class FakeReportData {
public:
  vector <int> generate(int N, int D) {
    vector <int> result(N);
    REP(n,N) {
//       cerr << endl; MSG(n);
      REP(d,D) {
        int digit;
        if (d == 0) {
          digit = n+1;
        } else if (d == D-1) {
//           MSG(n+1) MSG(digit);
          digit = n+2;
        } else {
          digit = n+2+d;
        }
//         MSG(d) MSG(digit);
        result[n] += (digit % 10) * pow(10, d);
      }
    }

    return result;
  }
};
