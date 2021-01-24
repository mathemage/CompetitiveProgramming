/* ========================================
 * Points : 998.74 - 553.83
 * Total : 1000
 * Status : WA (#5,#13) - AC
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


class MarbleDrawGame {
public:
  vector<vector<long long>> pascalTriangle(int N) {
    vector<vector<long long>> nCr(1+N);
    REP(row,1+N) {
//       MSG(row);
      nCr[row].assign(1+row,1);
      for (int col = 1; col < row; ++col) {
//         MSG(col);
//         MSG(row-1); MSG(col-1);
        nCr[row][col] = nCr[row-1][col-1] + nCr[row-1][col];
      }
    }
    return nCr;
  }

  double winningChance(vector <int> marbles) {
    vector<vector<long long>> nCr = pascalTriangle(55);
    int m = accumulate(ALL(marbles), 0);
    double result = 0.0;

    for (auto & mi : marbles) {
      if (mi < 5) {
        continue;
      }

      MSG(mi); MSG(min(9,mi));
      FO(select,5,min(9,mi)) {
        MSG(m-mi); MSG(select); MSG(9-select);
        MSG(nCr[m-mi][9-select]); MSG(nCr[mi][select]);
        MSG(nCr[m-mi].size());
        double numerator = double(nCr[mi][select]);
        numerator *= double(m-mi>=9-select ? nCr[m-mi][9-select] : 0);
        result += numerator;
        MSG(numerator);
        cerr << endl;
      }
      cerr << endl;
    }
    double denominator = double(nCr[m][9]);
    MSG(denominator); cerr << endl;
    return result / denominator;
  }
};
