/* ========================================
 * Points : 290.97
 * Total : 500
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define REVALL(A)     (A).rbegin(), (A).rend()
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;


class ChristmasLightsFixing {
  vector<vector<long long>> nCr;
public:
  void pascalTriangle(int N) {
    nCr.reserve(1+N);
    REP(row,1+N) {
//       MSG(row);
      nCr[row].assign(1+row,1);
      for (int col = 1; col < row; ++col) {
//         MSG(col);
//         MSG(row-1); MSG(col-1);
        nCr[row][col] = nCr[row-1][col-1] + nCr[row-1][col];
      }
    }
  }

  vector <int> fixingTime(int N, long long step) {
    pascalTriangle(N);
//     for (auto & row : nCr) {
//       for (auto & x : row) {
//         cout << x << " ";
//       }
//       cout << "\n";
//     }

    // target cardinality
    int cardinality = 1;
    while (nCr[N][cardinality] < step) {
      step -= nCr[N][cardinality];
      cardinality++;
    }
    
    // target elements
    vector <int> result;
    int slots = cardinality-1;
    REP(elem,N) {
      int choices = N-elem-1;
      if (choices < 0 || slots < 0) {
        break;
      }

      if (nCr[choices][slots] < step) {
        step -= nCr[choices][slots];
      } else {
        result.push_back(elem);
        slots--;
      }
    }

    nCr.clear();
    return result;
  }
};
