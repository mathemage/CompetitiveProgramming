/* ========================================
 * Points : 
 * - coding kata #1: 152.07 (WA-C)
 * - coding kata #2: 283.57 (AC)
 * - coding kata #3: 283.97 (AC)
 * Total : 300
 * Status : AC
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
    vector <int> result(N,0);
    REP(row,N) {
      REP(col,D) {
        result[row] += ((row + col + 1) % 10) * pow(10, D - 1 - col);
      }
    }

    return result;
  }
};
