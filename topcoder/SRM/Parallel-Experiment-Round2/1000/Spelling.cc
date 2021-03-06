/* ========================================
 * Points : 395.51
 * Total : 1000
 * Status : AC
 ==========================================*/

#include <bits/stdc++.h>
using namespace std;

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
#define MSG(a) cout << #a << " == " << a << endl;


class Spelling {
  const int inf = 1<<8;
public:
  int levehstein(string a, string b) {
    int m = a.size(), n = b.size();
    if (abs(m-n) > 1) return inf;

    int res = 0;
    if (m == n) {
      REP(i,m) {
        if (a[i] != b[i]) res++;
      }
      return res;
    }

    res = 2;
    if (m > n) {
      res = 3;
      swap(a,b);
      swap(m,n);
    }
    int d = inf;
    REP(j,n) {
      int k = 0, c = 0;
      REP(i,j) {
        if (a[k++] != b[i]) c++;
      }
      FOR(i,j+1,n) {
        if (a[k++] != b[i]) c++;
      }
      d = min(d, c);
    }
    res += d;
    return res;
  }

  int distance(vector <string> dictionary, string word) {
    int d = -1;
    for (auto & x : dictionary) {
      int l = levehstein(word, x);
      if (d == -1 || d > l) {
        d = l;
      }
    }

    if (d == inf) return -1;
    return d;
  }
};
