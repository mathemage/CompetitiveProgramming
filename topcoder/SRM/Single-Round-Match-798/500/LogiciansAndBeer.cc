/* ========================================
 * Points : 420.87
 * Total : 500
 * Status :
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
#define SGN(X) ((X) ? ( (X)>0?1:-1 ) : 0)
#define MSG(a) cerr << #a << " == " << a << endl;

const int CLEAN = -1;
const int UNDEF = -42;


class LogiciansAndBeer {
public:
  int bringBeer(string responses) {
    int result = 0;
    int n = responses.size();

    REP(i,n) {
      if (responses[i] == '?') {
        result++;
      } else if (responses[i] == '+') {
        if (i != n-1) {
          return -1;
        } else {
          return ++result;
        }
      } else {
        while (++i < n) {
          if (responses[i] != '-') {
            return -1;
          }
        }
        return result;
      }
    }

    return -1;
  }
};
