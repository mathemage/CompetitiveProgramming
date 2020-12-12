/* ========================================
 * Points : 338.09
 * Total : 500
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


class VertexMove {
public:
  double largestTriangleArea(int a, int b, int c) {
    double x = max(a, max(b, c));
    double p = (a + b + c) / 2.0;
    double S = sqrt(p * (p - a)* (p - b) * (p - c) );
//     MSG(x) MSG(p) MSG(S);
    return S + x / 2;
  }
};
