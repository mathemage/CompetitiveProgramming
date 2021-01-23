/* ========================================
 * Points : 264.77
 * Total : 300
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


class SyllableCountEstimator {
public:
  int estimate(string W) {
    int n = W.size();
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int result = 0;
    for (auto & c : W) {
      if (vowels.count(c)) {
        result += 1;
      }
    }

    for (int start = 0; start + 1 <= n-1; start += 1) {
      if (W.substr(start,2) == "au") { result--; }
      if (W.substr(start,2) == "oa") { result--; }
      if (W.substr(start,2) == "oo") { result--; }
    }
    for (int start = 0; start + 2 <= n-1; start += 1) {
      if (W.substr(start,3) == "iou") { result--; }
    }

    if (W[n-1] == 'e') {
      result--;
      if (n>=3 && vowels.count(W[n-3]) == 0 && W[n-2] == 'l') {
        result++;
      }
    }
    return max(1,result);
  }
};
